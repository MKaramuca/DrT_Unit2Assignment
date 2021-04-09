//Dr_T Unit 2 COSC-1437 Starter 
/* Task -

Top level solution folder: C_STL_Library_YourLastName

create a single main.cpp that contains code samples and implementations of each of the following topics */

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <cassert>
#include <stack>
#include <set>
#include <utility>
#include <map>

using namespace std; 
//creating another datatype (map)
typedef map<string, int> MapT; 
typedef MapT::const_iterator MapIterT;

//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector1 
{ 
  private:  
      vector<int> vec; 
  public: 
      MyClassVector1 (vector<int> v)  //parameterized constructor
      { 
        vec = v; 
      } 
      void print() 
      { 
          /// print the value of vector 
          for (int i = 0; i < vec.size(); i++) 
          {
              cout << vec[i] << " "; 
          }    
      } 
};

class MyClassVector2 
{ 
  private:  
      vector<double> vec; 
  public: 
      MyClassVector2 (vector<double> v)  //parameterized constructor
      { 
        vec = v; 
      } 
      void print() 
      { 
          /// print the value of vector 
          for (int i = 0; i < vec.size(); i++) 
          {
              cout << vec[i] << " "; 
          }    
      } 
};

class MyClassVector3 
{ 
  private:  
      vector<string> vec; 
  public: 
      MyClassVector3 (vector<string> v)  //parameterized constructor
      { 
        vec = v; 
      } 
      void print() 
      { 
          /// print the value of vector 
          for (int i = 0; i < vec.size(); i++) 
          {
              cout << vec[i] << " "; 
          }    
      } 
};

class less_than{
  public: 
  less_than(int t) : m_thresh(t){
  }
  bool operator()(int v){
    return v < m_thresh;
  }
  private:
    int m_thresh;
};

int main(int argc, char* argv[]) 
{
    /****Section_Name***Vectors*/ 
    //Write the base code for: 5. std::vector example
    vector<double> vd; //vd elments are floating point numbers
    vector<int> vi; //vi elements are integer numbers 
    vector<string> vs; //vs elements are string objects 

    //Expand this code to:

    //add 3 elements to the vd vector
    vd.push_back(1);
    vd.push_back(2);
    vd.push_back(3);
    vd.push_back(55.4); 

    //add 3 elements to the vi vector
    vi.push_back(10);
    vi.push_back(20);
    vi.push_back(30);

   // add 3 elements to the vs vector

    vs.push_back("hello");
    vs.push_back("world");
    vs.push_back("C++");


   // display the 3 elements in the vd vector
   cout << "\nValues in vd: \n"; 
   for(double vals : vd)
   {
     cout << vals << endl; 
   }
   cout << "\nAnother way to print vector: " << endl; 
   for(int i = 0; i < vd.size(); i++)
   {
     cout << vd[i] << endl; 
   }

    //display the 3 elements in the vi vector
    cout << "\nValues in vi: \n"; 
    for(int i = 0; i < vi.size(); i++)
    {
      cout << vi[i] << endl; 
    }

   // display the 3 elements in the vs vector
   cout << "\nValues in vs: \n"; 
   for(int i = 0; i < vs.size(); i++)
   {
     cout << vs[i] << endl; 
   }

    /****Section_Name***Vector_as_Class_Member*/ 
    //Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/

   cout << "\nVector_as_Class_Member_1" << endl; 
    vector<int> vecI; 
        for (int i = 1; i <= 5; i++) 
            vecI.push_back(i); 
        MyClassVector1 obj1(vecI); 
        obj1.print(); 
      
      //Continue with MyClassVector2 and MyClassVector3

      cout << "\nVector_as_Class_Member_2" << endl; 
    vector<double> vecD; 
        for (int i = 1; i <= 5; i++) 
            vecD.push_back(i*10.1); 
        MyClassVector2 obj2(vecD); 
        obj2.print(); 


        cout << "\nVector_as_Class_Member_3" << endl; 
    vector<string> vecS; 
        vecS.push_back("Hello");
        vecS.push_back("World");
        vecS.push_back("c++");
        MyClassVector3 obj3(vecS); 
        obj3.print(); 

    /****Section_Name**x*STL_Iterators*/ 
    vector <int> vint(3); //vector with 3 integer numbers
    vint[0]=10;
    vint[1]=20;
    vint[2]=30;

    //expanding the code to display 10 elements
    vint.resize(10);
    for(int i = 3; i < 10; i++){
      vint[i] = 10 * i + 10;
    }

    //display elements of the vector:

    vector <int> ::iterator it;
    for(it = vint.begin(); it != vint.end(); ++it){
      cout << endl << " " << *it;
    }

    /****Section_Name*** Stack*/

    stack < int > st; //declares the stack named stack

    st.push(100);     //stack is FILO, pushes 100 (top of stack)
    assert(st.size() ==1);  //checks the size of the stack
    assert(st.top() == 100);  //checks the top value of the stack

    st.top() = 456;   //changes the top value of the stack to 456
    assert(st.top() == 456);  //checks the top value of the stack is now the changed value
    st.pop(); //pops the stack (deletes the top of the stack and returns that number, but number is not used)
    assert(st.empty() == true); //checks if stack is empty, which after popping it's only element, it is

    //Write comments that help one better understand what the code is doing.

    
    /****Section_Name**** Set*/
    //Write the code as presented in: 3. std::set

    set <int> iset;  //declares/initializes the set

    //inserts the following vlaues into the set, 22 is added only onces as it is a set
    iset.insert(11);
    iset.insert(-11);
    iset.insert(55);
    iset.insert(22);
    iset.insert(22);

    //checks if 55 is in the set, if not it adds 55 to the set
    if(iset.find(55) != iset.end() ) {
      iset.insert(55);
    }

    assert (iset.size() == 4);  //making sure the set size is 4, as we added two 22's, "sanity check"

    set <int> ::iterator it1; //iterator, changed to it1 as it was used previously
    
    //uses the iterator to go through the set and output the values onto the screen with a pointer
    for(it1 = iset.begin(); it1 != iset.end(); it1++){
      cout << " " << *it1;
    }

    //Write comments that help one better understand what the code is doing.

    /****Section_Name****Pair_Structure*/
    //Write the code as presented in: 4. std::pair structure
    //initializing the pair (2 strings)
    pair <string, string> strstr;
    strstr.first = "hello";
    strstr.second = "World";
    //pairs "hello" and "world"
    //initializing the pair (1 int and 1 string)
    pair<int, string> intstr;
    intstr.first = 1;
    intstr.second = "one";
    //pairs 1 and "one"
    //string and int (reverse of previous), pairing "two" and 2 (done in one line)
    pair< string, int> strint("two",2);
    assert(strint.first == "two");
    assert(strint.second == 2);
    //checks the first and second value of the pair (sanity check)

    //Write comments that help one better understand what the code is doing.

    /****Section_Name**** Map_Insert*/
    //Write the code as presented in: 14. std::map::insert

    

    MapT amap; //using the typedef above, string and int
    pair< MapIterT, bool> result = amap.insert(make_pair("Fred", 45)); //insterts elements
    assert(result.second == true);  //sanity checks for 45
    assert(result.first->second == 45); //2nd sanity check

    result = amap.insert(make_pair("Fred", 54)); //result.first simply points there now
    assert(result.second == false); //3rd sanity check for the value that was changed
    assert(result.first->second ==45);  //sanity check for the value that was changed (fred was already in the map)


    //Write comments that help one better understand what the code is doing.

    /****Section_Name****Map_Summary*/
    //Write the code as presented in: 16. Map summary

    map <string, string> phone_book;  //mapping 2 strings (key and value)
    phone_book[ "411" ] = "Directory";  //411 is the directory (inserting)
    phone_book[ "911" ] = "Emergency";  //911 is emergency (inserting)
    phone_book[ "508-678-2811" ] = "BCC"; //"###..." is for BCC
    //if 411 isn't in phone_book, add the pair
    if(phone_book.find("411") != phone_book.end()){
      phone_book.insert(make_pair(string("411"),string("Directory")));
    }
    //check the vooksize is 3 (411, 911, and BCC)
    assert(phone_book.size() ==3);
    //output everything in phone_book
    map<string, string> ::const_iterator it2;
    for(it2 = phone_book.begin(); it2!= phone_book.end(); it2++){
      cout << " " << it2->first << " " << it2->second << endl;
    }

    /*output: 411 Directory
    508-678-2811 BCC
    911 Emergency
    */


    //Write comments that help one better understand what the code is doing.

    /****Section_Name**** Sort_Algorithm*/
    //Write the code as presented in: 23. sort example

    int arr[100]; //initialize an array of 100 element
    sort(arr, arr+100); //sorts in ascending order of, sort(begin, end)

    vector<int> v1;   //initializes the array, v1
    sort(v1.begin(), v1.end()); //same as sort, but with the vector



    //Write comments that help one better understand what the code is doing.

    /****Section_Name****Predicate_Algorithm*/
    //Write the code as presented in: 25. count_if and predicate function

    vector <int> v2;  //initiailzed the vector v2
    int x = 14; //initializes and declares x as 14

    int count_less = std::count_if(v1.begin(), v1.end(), less_than(x)); //calls on count_if with (v1.begin, v1.end, and less_than(x(14)))

    //count_if returns the # of elements in a range for which less_than(14) fybctuib us trye

    

    //Write comments that help one better understand what the code is doing. 

      return 0; 
 }