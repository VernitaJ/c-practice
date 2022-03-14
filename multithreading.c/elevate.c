#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> //header imported to use the random function and malloc
#include <time.h> //header imported to use the random function

//defining the maximum number of floors
#define max 20

//the function executed by the elevator thread
void *elevator(void *param);
//to acquire an integer value
int acquireFloor(int min,int m);
//function to clear the input buffer
void clear_stdin();

//declaring and initializing the mutex semaphore with a macro
pthread_mutex_t isMovingSem=PTHREAD_MUTEX_INITIALIZER;
//definining a shared variable whose meaning is to store if the elevator is moving or not
int isMoving=0; //0 is not moving 1 it is
//declaring a variable whose meaning is to store the current floor
int currentFloor=0;
//definining a shared variable whose meaning is to store the current destination floor of the elevator
int destination;


int main(){

	//decaring the two message strings for the user
	char msg[2][100] ={"waiting for user","moving"};
	//declaring the thread variable for the elevator
	pthread_t elevatorTh;
	
	//creating the thread and starting executing the function specified for the specified thread (first argument), the if statement checks if the value returned is != 0, if so an error occurred
	if(pthread_create(&elevatorTh,NULL,elevator,NULL)){
		//informing the user and returning with an error code
		printf("th. NON CREATO\n");
		//returning an error code
		return -1;
	}
	//printing info for the user
	printf("-1 : print status \n 0-%d: to select a floor\n\n", max);

	//this is the main thread:
	while(1){
		//acquiring an integer from the user (if -1 then the user wants to know the status of the elevator)
		int floor=acquireFloor(-1,max); //IF THIS function is considered plagmarims, then in this line please consider: scanf("%d",&floor); //IT DOES THE SAME WORK, just is not 'user proof'
		//locking the specified mutex semaphore (acquiring it)
		pthread_mutex_lock(&isMovingSem);
		//checking if the suer just wants to print the status
		if(floor==-1){ //if so we print the status thanks to the strings previously delcared
			printf("------- STATUS: %s\n",msg[isMoving]);
		}else{
			//if it was requested to go to a valid floor (0-20)
			//if the elevator is already moving print an error message
			if(isMoving==1){
				printf("THE ELEVATOR IS ALREADY MOVING\n");
			}else{
				//otherwise set the elevator to 'moving'ù
				isMoving=1;
				//set also the destination floor
				destination=floor;
			}
		}
		//releasing the semaphore
		pthread_mutex_unlock(&isMovingSem);
	}
	//joining the thread specified to the main th., so it ends just after the specified th. has terminated
	pthread_join(elevatorTh,NULL);
}
void *elevator(void *param){
	//endless loop
	while(1){
		//locking the specified mutex semaphore (acquiring it)
		pthread_mutex_lock(&isMovingSem);
		//if the semaphores moving then, either it was moving before or a request was made
		if(isMoving==1){
			//printing the current floor
			printf("Curernt Floor %d\n", currentFloor );
			if(currentFloor>destination){ //if we are at an higher floor, go down
				currentFloor--;
			}else if(currentFloor<destination){//if we are at an lower floor, go up
				currentFloor++;
			}else{
				//otherwise if we are arrived, inform the user and also stop the elevator (by setting the variable below)
				printf("Arrived.\n");
				isMoving=0;
			}
		}
		//unlocking the specified mutex semaphore (releasing it)
		pthread_mutex_unlock(&isMovingSem);
	
		//waiting 1 sec, the time for passing a floors
		sleep(1);

	}

	//making the thread return, null value
	pthread_exit(NULL);
}




//the following function is from my group (2), IT WAS ALSO ORIGINALLY WRITTEN BY ME IN ONE OF THE LABS (one of the first labs, i don't remember which).
//what it does it's just safely acquire a value between min and max, if this is considered plagmarism, a scanf does the same as this function it's does not check the values though	
int acquireFloor(int min,int m){
	
	int inputVal; //acquired val
	
	char endLine; //to check if the value insered is actually an integer
	int wrongInput=0;// a 'boolean' value to keep track of the (wrong) user input 

	do{
		//the input is not yet wrong
		wrongInput=0; 
		//asking the user to insert a value
		printf("insert a valid (%d-%d) value: ",min,m);
		//acquiring the user answer inputVal, and also acquiring a new line character to make sure an integer is insered
		if(scanf("%d%c", &inputVal, &endLine) != 2 || endLine != '\n'){
         	//clean the input buffer after reading the input
         	clear_stdin();
         	//printing an error message to the user
         	perror("\n**ERROR: unexpected value in input**\n"); 
         	//the value insered is not correct, so wrongInput=1;
         	wrongInput=1;
        }

	//the user is asked to insert a coordinate value untill it's a value between min and max (and it's a number, the last condition in the do-while guard checks this)
	}while((inputVal>m || inputVal<min) || wrongInput==1);
	
	//returning the value read
	return inputVal;
}
//to clear the stdin buffer since fflush on unix doesn't work
void clear_stdin(){
	//'moving' forward the pointer related with the stdin buffer, until \n
    while(getchar() != '\n' ){
        ;
    }
}