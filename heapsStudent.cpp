//#include "heaps.h"
#include<string>
#include<iostream>
#include<queue>
#include<stddef.h>

using namespace std;

//The heap struct
struct Heap{
    string name;
    Heap *left;
    Heap *right;
} ;

Heap *heapFromArray(string *input, int length);//Q2

int numElements(Heap h) ;//Q3

int lengthOfContent(Heap h);//Q4

string *printLinear(Heap h);//Q5

Heap *returnAllHeaps(Heap h);//Q5

string* heapToArrayHelper(Heap h,int n);//Q5.5a

string* heapToArrayHelperQ6(Heap h,int n);

string printPretty(Heap h);




int main(){
        // input for testing
         string maBands[] = {"Led Zeppelin", "The Beatles", "Pink Floyd", "Queen", "Metallica","ACDC", "Rolling Stones", "Guns N' Roses", "Nirvana", "The Who", "Linkin Park", "Green Day", "Black Sabbath", "RHCP"};

        //the size of the array (i.e. 14)
        int n = sizeof(maBands)/sizeof(maBands[0]);//elements in the array = 14

        //Creating a heap array
        Heap* pHeaps = new Heap();

    /*------------------------------------------------------------Q2--------------------------------------------------------------WORKS*/
    //Question Q2
        //Creating heap by calling the heapFromArray function which takes in a string array and the size of the heap
    
        pHeaps = heapFromArray(maBands,n);
    
        //CHECKING prints 14 elements
        //output the struct name of the array
        /*cout<<"Q2) The heap array created: "<<endl;
        for(int i=0;i<n;i++){
                cout<<pHeaps[i].name<<endl;
         }
         */

    /*------------------------------------------------------------Q3--------------------------------------------------------------*/
    
    //Question Q3
        //Count the number of elements in the heap
    
        int num=numElements(*pHeaps);
    
        //CHECKING
        //Printing the number of elements out
        //cout<<"Main) number of elements: ";
        //cout<<num<<endl;//Prints 14;
    
    
     /*------------------------------------------------------------Q4--------------------------------------------------------------*/
    
    //Question Q4
        //count the length of content
        lengthOfContent(*pHeaps);
    

    /*------------------------------------------------------------Q5--------------------------------------------------------------*/

   //Question Q5b
        //turning the tree into an array
        string* heapStoredArray= new string[14];
        heapStoredArray=printLinear(*pHeaps);
    
        //CHECKING
        //outputs the size of the string array
        //cout<<"size of array: ";
        //cout<<sizeof(heapStoredArray)<<endl;
        //CHECKING
        //Prints the string array
    
        //cout<<"Main) String Array: ";
        /*for(int i=0;i<num;i++){
            cout<<*(heapStoredArray+i)<<endl;
        }*/
    
    /*------------------------------------------------------------Helper--------------------------------------------------------------*/
        //Helper array
    
        heapToArrayHelper(*pHeaps,0);
    
        //CHECKING
        //heap name access
    
        //cout<<"Helper print pHeaps.name: ";
        //cout<<testing[0]<<endl;
    
    /*------------------------------------------------------------Q6--------------------------------------------------------------*/
    	//Question 6 
    	printPretty(*pHeaps);
    
    
    
    
    /*------------------------------------------------------------Helper--------------------------------------------------------------*/
    /*int fractal=1;// this is the fractal level of the triangle
    int h = 20;//height of triangle
    int i;
    //sscanf(argv[1],"%i", &h);
    const int y = 1;//the y axis point to start printing at
    const int x = ((h*2-1)+1)/2;//the x axis point to start printing at
    int s[260][260];//int array to store the sierpinskin triangle
    sierpinski(s,fractal,h,y,x);
    cout<<endl;
    cout<<endl;
    draw(s,h);*/
    
}
/*----------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------Q2--------------------------------------------------------------*/

//Question 2 Q2c, takes in an array of string and returns a heap struct
Heap *heapFromArray(string *input, int length) {
    
        //CHECKING
        //the length of r=the array that will be created
        //cout<<"Q2) length used to define array: ";
        //cout<<length<<endl;
    
        //initializing a heap array
        Heap* pHeaps = new Heap[length];
    
    
    
        //Assigning the content into the heap array
        for(int i=0;i<length;i++){
                //Filling up the array
                pHeaps[i].name=input[i];

                //when the last position has a left child only
                if(2*i+2==length-1){
                        pHeaps[i].left=nullptr;
                }

                //when the last position does not have children
                else if(2*i+2>length){
                        pHeaps[i].left=nullptr;
                        pHeaps[i].right=nullptr;
                }

                //when position has left and right children
                else{
                        pHeaps[i].left = &pHeaps[2*i+1];
                        pHeaps[i].right = &pHeaps[2*i+2];

                }
            
            //CHECKING
            //The content entered into the array
            //cout<<"Q2) The content entered into the array: "<<endl;
            //cout<<pHeaps[i].name<<endl;

	}
	return pHeaps;
}


/*------------------------------------------------------------Q3--------------------------------------------------------------*/

int recursion(Heap h,int n){
    static int count=0;
    
    if(h.left!=NULL){
        recursion(*h.left,2*n+1);
    }
    if(h.right!=NULL){
        recursion(*h.left,2*n+2);
    }
    count++;
    return count;
}

//Question 3 Q3c
//Count the number of elements
int numElements(Heap h) {
    int numOfelements;
    int n=0;
    numOfelements=recursion(h,n);
    //CHECK
    //cout<<"Q3.b) count: "<<endl;
    //cout<<numOfelements<<endl;
    return numOfelements-1;
}

/*------------------------------------------------------------Q4--------------------------------------------------------------*/
int elementsHelper(Heap h,int n){
    static int length=0;
    
    if(h.left!=NULL){
        elementsHelper(*h.left,2*n+1);
        for(int i=0;h.left->name[i]!='\0';i++){
            length++;
        }
    }
    if(h.right!=NULL){
        elementsHelper(*h.left,2*n+2);
        for(int i=0;h.right->name[i]!='\0';i++){
            length++;
        }
    }
    
    return length;
}

//Question 4 Q4c
//count the lenght of the content
int lengthOfContent(Heap h){
    int lengthContent;
    lengthContent=elementsHelper(h,0);
    //CHECKING
    //cout<<"length of content: "<<endl;
    //cout<<lengthContent<<endl;
	return lengthContent;
}


/*------------------------------------------------------------Q5--------------------------------------------------------------*/

// might want to do this for Q5
/*
Heap *returnAllHeaps(Heap h) {
    //A pointer of a pointer of a heap
    Heap** ppHeaps;
    
    //Pointer of a heap
    Heap* pHeaps = new Heap[15];
    
    pHeaps[0].name=h.name;
    pHeaps[1].name=h.left->name;
    pHeaps[2].name=h.right->name;
    pHeaps[3].name=h.left->left->name;
    pHeaps[4].name=h.left->right->name;
    pHeaps[5].name=h.right->left->name;
    pHeaps[6].name=h.right->right->name;
    pHeaps[7].name=h.left->left->left->name;
    pHeaps[8].name=h.left->left->right->name;
    pHeaps[9].name=h.left->right->left->name;
    pHeaps[10].name=h.left->right->right->name;
    pHeaps[11].name=h.right->left->left->name;
    pHeaps[12].name=h.right->left->right->name;
    pHeaps[13].name=h.right->right->left->name;
    
    cout<< "1-13: ";
    for(int i = 0;i<14;i++){
        cout<<pHeaps[i].name<<endl;
    }
    return pHeaps;
}
*/


//Question5 Q5c
string *printLinear(Heap h) {
    string *arrayPointer;
    arrayPointer=heapToArrayHelper(h,0);
    
    //cout<<"Q5) Print out array:"<<endl;//printing out the
    /*for(int i=0;i<14;i++){
        cout<<*(arrayPointer+i);
    }*/
    return arrayPointer;
}

//Q5 Helper
string* heapToArrayHelper(Heap h,int n){
    //string arrayHelper[15];
    static string* arrayHelper=new string[15];
    string *p;
    arrayHelper[n]=h.name;
    
    //CHECKING
    //cout<<"Q5.5) Test in heapToArrayHealper for looking at the content in h.name: ";
    //cout<<arrayHelper[0]<<endl;
    
    if(h.left!=NULL){
     heapToArrayHelper(*h.left,2*n+1);
        //arrayHelper[2*n+1]=h.name;
    }
    
     if(h.right!=NULL){
     heapToArrayHelper(*h.right,2*n+2);
         //arrayHelper[2*n+1]=h.name;
     }
    //CHECK
    //Return the number of n
    //cout<<"Q5.5) Print the count: ";
    //cout<<n<<endl;
    //cout<<"Helper) print array:"<<endl;
    p = arrayHelper;
    
    return p;
}

/*------------------------------------------------------------Q6--------------------------------------------------------------*/

string* heapToArrayHelperQ6(Heap h,int n){
    //string arrayHelper[15];
    static string* arrayHelper=new string[15];
    string *p;
    arrayHelper[n]=h.name;
    
    //CHECKING
    //cout<<"Q5.5) Test in heapToArrayHealper for looking at the content in h.name: ";
    //cout<<arrayHelper[0]<<endl;
    
    if(h.left!=NULL){
        heapToArrayHelperQ6(*h.left,2*n+1);
        //arrayHelper[2*n+1]=h.name;
    }
    
    if(h.right!=NULL){
        heapToArrayHelperQ6(*h.right,2*n+2);
        //arrayHelper[2*n+1]=h.name;
    }
    //CHECK
    //Return the number of n
    //cout<<"Q5.5) Print the count: ";
    //cout<<n<<endl;
    //cout<<"Helper) print array:"<<endl;
    p = arrayHelper;
    
    return p;
}

string printPretty(Heap h) {
    string *arrayPointer;
    arrayPointer=heapToArrayHelperQ6(h,0);
    /*
    for(int i=0;i<14;i++){
     cout<<*(arrayPointer+i);
     }
    */
  
    
    cout<<*(arrayPointer+0)<<endl;
    cout<<*(arrayPointer+1);
    cout<<*(arrayPointer+2);
    return 0;
    
}


//setting up position of the print pretty
void position(int s[260][260], int h,int y,int x)
{
    
    int r = 0;
    int i;
    for(i = y; i< (y+h);i++){
        int j;
        for(j = 1 ; j <= x+(h*2-1); j++){
            if(j>=(x-r) && j<(x-r+(r+1)*2-1)){ 
                s[i][j] = 1;
            }
        }
        r++;
    }
}










