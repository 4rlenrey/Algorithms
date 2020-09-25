#include <iostream> 

using namespace std;

int linearSearch(int array[], int x, int size)  // finds index of x in array
{
    for(int i = 0; i < size; i++)
        if(array[i] == x)   
            return i;
   
    return 0; //if can't find anything
}

int binarySearch(int array[], int x, int size) // finds index of x in array
{
    //when asking someone for age do not use this technique 
    //even if its effective! haha

    int start = 0;
    int end = size-1;
    int middle = 0;

    while (start < end)
    {
        middle = (start+end)/2;
        if(array[middle] >= x)
            end = middle;
        else 
            start = middle + 1;
    }

    if(start == end)
    {
        return start; //return index of this element
    }

    return 0; //if can't find anything
}


int main()
{
    int s[] = {2,3,4,5,2,6};
    cout << binarySearch(s, 4, 6) << "\n";
    cout << linearSearch(s, 4, 6) << "\n";

}