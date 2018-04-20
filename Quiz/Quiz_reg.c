#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	 char name[30];
	 int score;
	struct node* link;
}node;
 int Main_Quiz(); 
node* Inseration();
void Display(int*);
int length();
void Delete();
void bubbleSort(struct node*,int*,int);
void swap(struct node*, struct node*);

	struct node* root=NULL;
main()
{ 
int ch,ch1,ch2,a,scor[10]={0,0,0,0,0,0,0,0,0,0},i=0,j=0,k=0;
char ch3;
        	struct node* temp=NULL;
                 	 temp=(node*)malloc(sizeof(node));
   while(1)
   {
   	 printf("Select your option\n1.Admin\t2.Student\n");
  // 	scanf("%d",&ch);
   
  int  temp, status;


	status = scanf("%d", &ch);
	while(status!=1){
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid input... \nplease enter a correct option\n1.Admin\t2.Student\n ");
		status = scanf("%d", &ch);
		//continue;
	}



   	switch(ch)
   	{
   		case 1:
		   			printf("Adimin....\t");
		    char buffer[256] = {0};
		    char password[] = "password";
		    char c;
		    int pos = 0;
		    
		    printf("%s", "Enter password: ");
		    do {
		        c = getch();
		        
		        if( isprint(c) ) 
		        {
		            buffer[ pos++ ] = c;
		            printf("%c", '*');
		        }
		        else if( c == 8 && pos )
		        {
		            buffer[ pos-- ] = '\0';
		            printf("%s", "\b \b");
		        }
		    } while( c != 13 );
		    
		    if( !strcmp(buffer, password) )
		        printf("\n%s\n", "Logged on succesfully!");
		    else
		    {
			
		        printf("\n%s\n", "Incorrect login!");
		       continue;
		    }
        
  
		   
   	      while(1)
   	      {
		
	   	printf("\nEnter your choise:\n1.INSERATION Of New Record\n2.DISPLAY All The Records\n3.Number of Records\n4.DELETE\n5.Switch the user\n6.Arrange in Roll.No. Order\n7.Arrange According to Score\n");
	   	scanf("%d",&ch1);
	   	if(ch1==5)
	   	{
	   		break;
		   }
	   	switch (ch1)
	   	{
	   		case 1:
	   			root=Inseration();
	   		    i++;
	   		    k=0;
	   			printf("Registration is sucessful");
	   			break;
	   		case 2:
			     Display(scor);
			     printf("\n");
				 break;
			case 3:
			     a= length();
			     printf("\nTotal number of Records are %d: ",a);
				 break;
	        case 4:
				 Delete();
				 break;
		    case 6:
		    	  bubbleSort(root,scor,ch1);  //Sorting based on roll number
		    	   Display(scor);
			       printf("\n");
		    	break;
		     case 7:
		    	  bubbleSort(root,scor,ch1);  //Sorting based on Score
		    	   Display(scor);
			       printf("\n");
		    	break;	
			case 8:
			     exit(0);
	    	default:printf("invalid choise\n");	 	
		   }
	}
	   break;
	   	case 2:
	   		printf("\n1.Start Quiz\t2.Display Score\n");
	   		  	scanf("%d",&ch2);
	         	switch (ch2)
	         	{
				 
			     case 1:
			     	
                 
				    k=Main_Quiz();
				    scor[i]=scor[i]+k;
				   
					  printf("\n"); 
					      //main quiz
					 break; 
				case 2:
					
		             Display(scor);
		           
			         printf("\n");
			         break;	
				default:printf("Please choose option correctly\n");
				        continue;	     
			    }
				 break;
		
				default:printf("Please select appropriate option");         
		  
	   }
	   
   }
  
 
}

node* Inseration()
{
	
		struct node* temp=NULL;
	 temp=(node*)malloc(sizeof(node));
  printf("Enter the Roll Number :");
  scanf("%d",&temp->data);
   printf("Enter the Name :");
  scanf("%s",temp->name);
  temp->score=0;
   
  temp->link=NULL;
  if(root==NULL)
  {
  	root=temp;
  }
  else
  {
  	 struct node* p=NULL;
  	 p=root;
  	 
  	 while(p->link!=NULL)
  	 {
  	 	p=p->link;
	   }
	   p->link=temp;
  }
  return root;
}
void Display(int *scor)
{
	printf("Students Record:\n");
	struct node* temp=NULL;
   temp=root;
   int i=1;
   printf("Roll number\t\tName\t\tScore\n");
    while(temp!=NULL)
    {
	   
	 printf(" %d\t\t\t",temp->data);
	  printf("%s\t\t",temp->name);
	  temp->score=scor[i];
	   printf("%d\n",temp->score);
    temp=temp->link;
    i++;
    }
  
}
int length()
{
		struct node* temp=NULL;
   temp=root;
   int c=0;
    while(temp!=NULL)
    {
	
	 c++;
    temp=temp->link;
    }
   
    return c;
}
void Delete()
{
	int loc;
	printf("Enter the Roll Number of Student u want to delete: ");
	scanf("%d",&loc);
	
		
    if(loc>length())
    {
    	printf("invalid location\n");
	}
     else if(loc==1)
     {
     		struct node* temp=NULL;
     		temp=root;
     		root=temp->link;
     		temp->link=NULL;
     		free(temp);
     		printf("NUMBER is Deleted from loc. 1\n");
	 }
	 else
	 {
	 	int i=1;
	 	 struct node* p=root,*q;
	 	for(i=1;i<loc-1;i++)
	 	{
	 		p=p->link;
		 }
		 q=p->link;
		 p->link=q->link;
		 q->link=NULL;
		 free(q);
		printf("NUMBER is Deleted from loc. %d\n",loc);
	 }
	 
	
}

 int Main_Quiz()
 {
 		int i=0,j=0,c=0,k=0,ans1,ch;
	 char topic[30];
	   char source1[] = "Quiz_Questions1.txt"; 
	   char source2[] = "Quiz_Questions2.txt"; 
	   char source3[] = "Quiz_Questions3.txt"; 
	   char source4[] = "Quiz_Questions4.txt"; 
       char source5[] = "Quiz_Questions5.txt"; 	  
	int ans[5][20]={2,4,2,2,1,3,2,1,1,2,4,4,3,1,4,2,2,3,3,3,4,1,2,1,3,3,1,1,1,4,2,3,1,2,3,2,1,1,3,3};
	 printf("Select your topic\n1.Science\t2.Sport \t3.\t4.\t5.\n");
   	 	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		
		    
		    strcpy(topic, source1);    
		  
			break;
		case 2:
		strcpy(topic, source2);  
			break;
			case 3:
		strcpy(topic, source3);  
			break;
			case 4:
		strcpy(topic, source4);  
			break;
			case 5:
		strcpy(topic, source5);  
			break;
		default:
		    printf("Please choose topic correctly");				
		
			
	}
	      	
             FILE *file = fopen (topic , "r" );
  
   if ( file != NULL )
   {
      char line [ 200 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
         fputs ( line, stdout ); /* write the line */
         i++;
      
         if(i==13||i==28||i==40||i==51||i==61||i==72||i==82||i==93||i==102||i==111||i==121||i==130||i==140||i==150||i==160||i==170||i==180||i==190||i==200||i==210)   //logic to go on line u want
         {
         	
         	scanf("%d",&ans1);
         	if(ans[ch-1][j]==ans1)
         	{
         	
         		c++;	//counter for score
			 }
	       
	         else
	         {
	         	
			 }
			 	j++;
              k++;
	   }
	  
    }
     printf("\n%d is the score",c);
      fclose ( file );
   }
   else
   {
      perror (topic); /* why didn't the file open? */
   }
   return c;
 }

/* Bubble sort the given linked list */
void bubbleSort(struct node* root,int* scor,int ch1)
{
    int swapped, i=0;
    struct node *ptr1;
    struct node *lptr = NULL;
 
    /* Checking for empty list */
    if (root == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = root;
 
        while (ptr1->link != lptr)
        {
        
		   	i++;
		   	if(ch1==6)
	  	{
			   
            if (ptr1->data > ptr1->link->data)
            { 
                 int temp1 = scor[i];
                 scor[i] = scor[i+1];
                 scor[i+1] = temp1;
                swap(ptr1, ptr1->link);
                swapped = 1;
            }
        }
            else if(ch1==7)
        {
             if (scor[i] <scor[i+1])
            { 
                 int temp1 = scor[i];
                 scor[i] = scor[i+1];
                 scor[i+1] = temp1;
                swap(ptr1, ptr1->link);
                swapped = 1;
            }	
		}
        
            ptr1 = ptr1->link;
        }
        lptr = ptr1;
    }
    while (swapped);
}
 
/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
   
      char t[50] = "";
    strcpy(t,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,t);
}




