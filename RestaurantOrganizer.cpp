/*
Student Name: Yagiz Efe Sabanoglu
Student Number: 2017400108
Project Number: 2
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "RestaurantOrganizer.h"

using namespace std;

RestaurantOrganizer::RestaurantOrganizer(const vector<int>& tableCapacityInput){
    numberOfTables = tableCapacityInput.size();
    for(int i=0;i<numberOfTables;i++){
        tableCapacity[i] = tableCapacityInput[i];
        heap[i] = i;
        heapUp(i);
    }
}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream& outFile){
    // IMPLEMENT ME!

   if ( groupSize > tableCapacity[heap[0]]){
       outFile << "-1" << endl ;
   }
   else {
       outFile << heap[0] << endl ;
       tableCapacity[heap[0]] = tableCapacity[heap[0]]-groupSize;
       heapDown(0);

   }


}

void RestaurantOrganizer::heapUp(int index){
    // IMPLEMENT ME!
     if ( index == 0){
         return;
     }
    else {
        if (tableCapacity[heap[index]] > tableCapacity[heap[(index -1)/ 2]]) {

            swap(heap[index],heap[(index - 1) / 2]);
            heapUp((index - 1) / 2);

        }
    }
}

void RestaurantOrganizer::heapDown(int index){
    // IMPLEMENT ME!
    int l = 2*index+1;
    int r = 2*index+2;

    if(l==numberOfTables-1 ){
        if((tableCapacity[heap[l]]>tableCapacity[heap[index]])|| (tableCapacity[heap[l]]==tableCapacity[heap[index]]&&
        heap[l]==heap[index])){
            swap(heap[l],heap[index]);
        }
    }

        if ( (r< numberOfTables) && tableCapacity[heap[index]] < max(tableCapacity[heap[2*index+1]],tableCapacity[heap[2*index+2]])){
            if ((tableCapacity[heap[2*index+1]] > tableCapacity[heap[2*index+2]] ) ||
            (tableCapacity[heap[2*index+1]]==tableCapacity[heap[2*index+2]] && heap[2*index+1]<heap[2*index+2])){
                swap(heap[index],heap[2*index+1]);
                heapDown(2*index+1);

                }
            else {
                swap(heap[index],heap[2*index+2]);
                heapDown(2*index+2);
            }
        }
        else if ((r< numberOfTables)&& tableCapacity[heap[index]]==max(tableCapacity[heap[2*index+1]],tableCapacity[heap[2*index+2]])){
          if (tableCapacity[heap[index]]==min(tableCapacity[heap[2*index+1]],tableCapacity[heap[2*index+2]])){
              if(heap[index]>min(heap[2*index+1],heap[2*index+2])){
                  if (heap[index]>heap[2*index+1] && heap[2*index+1] < heap[2*index+1]){
                      swap(heap[index],heap[2*index+1]);
                      heapDown(2*index+1);
                  }
                  else {
                      swap(heap[index],heap[2*index+2]);
                      heapDown(2*index+2);
                  }
              }
          }
          else {
              if (tableCapacity[heap[2*index+1]] > tableCapacity[heap[2*index+2]] && heap[index]>heap[2*index+1] ){
                  swap(heap[index],heap[2*index+1]);
                  heapDown(2*index+1);
              }
              else if (tableCapacity[heap[2*index+1]] < tableCapacity[heap[2*index+2]] && heap[index]>heap[2*index+2]) {
                  swap(heap[index],heap[2*index+2]);
                  heapDown(2*index+2);
              }
          }
}
        }




void RestaurantOrganizer::printSorted(ofstream& outFile){
    // IMPLEMENT ME!

for ( int i = 0 ; i<numberOfTables ;i++){
    outFile << tableCapacity[heap[0]] << " " ;
    tableCapacity[heap[0]] = 0;
    heapDown(0);
}



}

// YOU CAN ADD YOUR HELPER FUNCTIONS

