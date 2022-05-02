#include<iostream>
using namespace std;

//CALL BY VALUE
	//any change to formal parameter won't affect actual parameter.

//CALL BY ADDRESS//
	//address passed, pointers recieve them
	//Need to use dereferencing in the body of function.

	//using pointer
	//actual parameter &a
	//formal parameter *a

void hi(int *a) {
	//indirectly accessing var of other funciton.
	//a func cannot access var of another func directly
	(*a)++;
}

//CALL BY REFERENCE// 
	//Does not take extra memory. Just different name
	//only in formal paramter add & sign.
	//rest of code are same as call by value.

	//actual parameter a
	//formal parameter &a 

//part of caller funciton. more like monolithic
void hi(int &a) {

	//this function is not a different func. Machine code is monolethic, though source code is procedural.
    //A func can't access var of another func directly.
    //Here, this function does not generate anything in stack. The vars in caller funciton are modified.	
	//not a separate function, just these code is pasted in the caller function.
	//Don't use it for heavy funciton with complex tasks and many loops.
	//this strong feature need to be used carefully.
	a++;
}

//passed an array
void fun(int A[], int n) {
	A[4] = 25;
}

//returning an array
int* fun2(int n) {
	int *pl;
	pl = (int *) malloc(n * sizeof(int));
	return pl;
}

///STRUCTURE///
	//to group related various varibale of various types.
	//It is a user defined data type.

    struct Rectangle {
    	int length;
    	int breadth;
    }; //Right now it doesn't occupy memory. //just a definition.
    //till a variable of this type is created.

//call by value.
void area(struct Rectangle r1) {
	r1.length = 2;
	//return r1.length * r1.breadth;
}

//call by reference
void area1(struct Rectangle &r1) {
	r1.length = 123;
	//return r1.length * r1.breadth;
}
//call by address
void area2(struct Rectangle *r2) {
	r2->length = 2;
	//arrow for accessing by pointer
}

struct test {
	int arr[5];
	int n;
};

void fun45(struct test t1) {
	t1.arr[0] = 99;
}

void fun46(struct test *t2) {
	t2->arr[0] = 99;
}

int main() { 
	//is like a manager, knows how to do
	//but assign works to his assistant meaning other functions.

    ios::sync_with_stdio(0);
    cin.tie(0);

//STRUCTURE
    //struct Rectangle r; //declaring
    struct Rectangle r = {10, 5}; //initializing
    r.length = 50;
    r.breadth = 10;
    cout << r.length * r.breadth << "\n";

    struct Student {
    	int roll;
    	char name[25];
    	char dept[20];
    	char address[50];
    };

    struct Student s;
    s.roll = 10;
    
    struct Card {
    	int face;
    	int shape;
    	int color;
    };

    struct Card c = {1, 0, 0};//initialize
    struct Card deck[52];//declaring
    //cout << deck[0].face;

///POINTER///
	//A address varibale meant for storing address of data not data itself.
	//Used for indirectly accessing data.

	//why need to access data indirectly?

	//A program will utilize the main memory by diving it into three section. 
	//Code section, Heap, Stack.
	//Program directly access code section and stack.
	//Heap memory is ouside/external to program.
	//To access it, program need pointer.

//Pointer is used to access the resources outside the program.
    //1) to access heap
    //2) to access resources
    //3) to pass parameter
     int d = 10;
     int *p;//* for declaring and dereferencing
     p = &d;
     //to access memoery in heap, malloc function is needed in C.
     //it is defined in stdlib.h
     //it takes size(in bytes)
     //returns void pointer, so need to typecast it.

     int *q = (int*) malloc(5*sizeof(int)); //sizeof operator is used to let compiler decide the size.
	//allocates heap memory. pointer q is pointing to the very first index memory of the array. 
	//Using that, we can access the entire array.

     q = new int[5]; //Syntax in C++

///REFERENCE/// 
	//nothing but another name given to a variable.
	//Data var = nothing in between data type & var name 
	//Pointer = * in between
	//Reference = & in between    

    int a = 10;
    int &b = a; //we can call a by b
    cout << ++b << " " << a << " ";
    hi(a);
    cout << a << " ";

///POINTER TO STRUCTURE///
	//Accessing propertes of Rectangle struct with pointer
	//Accessing static object & dynamic object

    struct Rectangle *p2, *p3; 
	//doesn't take the same bytes of structure itself.
	//usually take the same space in memory regardless of it's type except for function pointer
	//so it basically depends on architecture, either 4 byte or (8 byte for 64bit architecture).

    p2 = &r;//static object, already created
	//p.length is wrong, p is not a data variable,
	//it needs to go to the pointing address and access the data
	//so *p.length. But precedence of . is higher
    
    (*p2).length = 100; 
	//so that first it is dereferenced.
	//instead of all this we can use arrow operator
    p2->length = 150;
    cout << r.length << " ";

//FOR NORMAL VARIBALE, USE DOT OPERATOR
//FOR POINTER, USE ARROW OPERATOR

//Creating object dynamically using pointer

    p3 = (struct Rectangle *) malloc(sizeof(struct Rectangle));
    p3->length = 200;//dynamic object, at runtime.
    (*p3).breadth = 300;
    cout << p3->breadth << "\n";

///FUNCTION///
	//group of related instructions which performs specific task. 

	//Easy to maintain code and for team work to develop.
	///reusability //group function in library.
    //oop-group related funciton in a single class.
	//modular/procedural instead of monolithic code(everything in single body).

	//Actual parameter, Formal parameter, code section and  memory allocation
	//call by value, call by address, call by reference(in C++, not in C)
	//prototype/signature/header of a function->declaration
	//function body is definition/elaboration of function.
	    
	//when a function is called, it's own activation record or stack frame is created.
    //it will have it's own variable.
    //once the function ends, activation record is deleted.

    //one func can't directly access var of another func. //by pointer indirect access. 
    //by reference, basically no new func is created.

///ARRAY AS PARAMETER///
      //passed and returned
    int A[5] = {9, 99, 999, 9999, 109};
    fun(A, 5);
    cout << A[4] << " ";
	//Array is passed by address,
	//void fun(int a[], int n) //a[] or *a
	// [] means array only, * for any type pointer.
   //Returning an array
    int *A23;
    A23 = fun2(5);

///STRUCTURE AS PARAMETER.
	//structure passed as a single variable.
    area(r);
    cout << r.length << "\n";
    area1(r);
    cout << r.length << "\n";
    area2(&r);
    cout << r.length << "\n";

    //structure can be passed as call by value.
    //array can be passed as call by address only.  

//if a structure has an array inside, we can still pass it as call by value.
	//though time consuming, compiler will copy the array into formal parameter.
    //call by value
    struct test t = {{1, 2, 3, 4, 5}, 5};
    fun45(t);
    cout << t.arr[0] << "\n";

    //call by address
    fun46(&t);
    cout << t.arr[0] << "\n"; //value changed.

return 0;
}
