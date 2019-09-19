//Including all required header Files

#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <stdio.h>
#include<time.h>
//Defining Structure to hold Multiple Values and Array To be  pass to the function
struct thread_data{
   int *Mat1;
   int *Mat2;
   int *resMat;
   int r1,c1,r2,c2;

};

//Defining Function for taking input in matrix
void matrixInput(int *mat,int r,int c){

  int i=0,j=0;

  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        printf("\nEnter Element [%d][%d]: ",i,j);
        scanf("%d",(mat+i*c+j));
    }
  }

}

//Defining Function To Display Matrix
void dispMat(int *mat,int r,int c){

   int i=0,j=0;
   printf("\n");
   for(i=0;i<r;i++){
     for(j=0;j<c;j++){
       printf("%3d",*(mat+i*c+j));
     }
     printf("\n");
   }

 }

//Defining Function For Multipying Matrices
void *multiplyMat(void *args){
	printf("\n[INFO] Entering Thread\n");
	//typecasting args from void * to be the type of structure thread_data
    struct thread_data *mydata = (struct thread_data *) args;

    int k = 0;
    int i = 0;
    int j = 0;

	//Checking Necessary Condition For Matrix Multiplication
    if(mydata->c1 == mydata->r2){
      for(i=0;i<mydata->r1;i++){
        for(j=0;j<mydata->c1;j++){
          *(mydata->resMat+i*mydata->c1+j) = 0;
          for(k=0;k<mydata->r1;k++){
          	if(k%2==0){
          	printf("\ncalculating [%d][%d] * [%d][%d] + [%d][%d] * [%d][%d]",i,k,k,j,i,k+1,k+1,j);
          	}
            *(mydata->resMat+i*mydata->c1+j) = *(mydata->resMat+i*mydata->c1+j) + *(mydata->Mat1+i*mydata->c1+k) * (*(mydata->Mat2+k*mydata->c1+j));
          
          }
        }
      }
    }
    else{
      printf("\nMatrix Should Have Number of Rows of Matrix 1 equal to Number of Columns of Matrix 2");
      pthread_exit("\nPlease Provide Correct Arguements\n");
    }
	
	//Printing First Matrix
	printf("\n");
    printf("\nFirst Matrix Is: ");
    dispMat(mydata->Mat1,mydata->r1,mydata->c1);

	//Printing Second Matrix
    printf("\nSecond Matrix Is: ");
    dispMat(mydata->Mat2,mydata->r2,mydata->c2);
	
	//Printing Resulatant Matrix 
    printf("\nMultiplication of Matrices Is: ");
    dispMat(mydata->resMat,mydata->r1,mydata->c2);

	//thread exiting 
    pthread_exit("\nExecuted Successfully\n");
}                                                                      


int main(){

  //Declaring Variables	
  int *mat1,*mat2,*resMat;
  int r1=0,c1=0,r2=0,c2=0;
  pthread_t thread;
  int rc,*status;
	//Declaring Structure Variable
	struct thread_data data;
  //Taking Number of Rows and Columns From User
  printf("\nEnter Number Of Rows and Columns of Matrix 1: ");
  scanf("%d %d",&r1,&c1);
  //Assigning Memory to Matrix1
  mat1 = (int *)malloc((r1*c1)*sizeof(int));

  printf("\nEnter Number Of Rows and Columns of Matrix 2: ");
  scanf("%d %d",&r2,&c2);
  
  //Assigning Memory to Matrix2 and Resultant Matrix
  mat2 = (int *)malloc((r2*c2)*sizeof(int));
  resMat = (int *)malloc((r1*c2)*sizeof(int));

  //Calling Function matrixInput () for matrix values	
  printf("\nEnter Elements Of Matrix 1: ");
  matrixInput(mat1,r1,c1);


  //Calling Function matrixInput () for matrix values
  printf("\nEnter Elements Of Matrix 2: ");
  matrixInput(mat2,r2,c2);

  //assigning values to structure variable
  data.Mat1 = mat1;
  data.Mat2 = mat2;
  data.resMat = resMat;
  data.r1 = r1;
  data.c1 = c1;
  data.r2 = r2;
  data.c2 = c2;
	
  //Creating Thread Using pthread_create	
  printf("\n[INFO] Creating Thread");
  rc = pthread_create(&thread, NULL, multiplyMat, (void *)&data);
  //Checking Response Code
    if (rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
	
	//joining thread to main process
    rc = pthread_join(thread,&status);
	printf("\n%s",status);
    //Checking Response Code
    if (rc) {
        printf("ERROR; return code from pthread_join() is %d\n", rc);
        exit(-1);
    }
 
 	//Main Thread Exiting 
    pthread_exit(NULL);
  //matrixInput(mat2,r1,c1);

  return 0;


}
