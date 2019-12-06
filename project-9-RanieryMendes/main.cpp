#include <iostream>
#include <string>
#include "Data.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
using namespace std;

template <typename Bubble>

//code from Zybooks
void Merge(vector <Bubble> numbers, int i, int j, int k) {
    int mergedSize;                            // Size of merged partition
    int mergePos;                              // Position to insert merged number
    int leftPos;                               // Position of elements in left partition
    int rightPos;                              // Position of elements in right partition
    Bubble* mergedNumbers = nullptr;

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i;                               // Initialize left partition position
    rightPos = j + 1;                          // Initialize right partition position
    mergedNumbers = new Bubble[mergedSize];       // Dynamically allocates temporary array
    // for merged numbers

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;

        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
    delete[] mergedNumbers;
}

template <typename Bubble>
//code from Zybooks
void MergeSort(vector <Bubble> numbers, int i, int k) {
    int j;

    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);

        // Merge left and right partition in sorted order
        Merge(numbers, i, j, k);
    }
}
template <typename Bubble>
//code from lecture slides
void bubblesort (vector <Bubble> &v, int size){

    int i, j;
    bool swapped;

    for (i = 0; i < size-1; i++){

      swapped=false;
            // Last i elements are already in place
           for (j = 0; j < size-i-1; j++)
           if (v.at(j) < v.at(j+1)) {
              swap(v[j], v[j + 1]);
              swapped=true;
           } //if there wasn't any swap in the inner loop, stop

            if(!swapped)
            break;
    }

}
//code from lecture slides
/* Selection sort from min to max */
template <typename selection>
void MinSort(vector <selection>& v, int size) {
     int min;
for (int i = 0; i < size - 1; ++i) {
// Find index of smallest remaining element
    min = i;
    for (int j = i + 1; j < size; ++j) {
    if (v[j] < v[min]) {
    min = j;}
    }

    swap(v[i],v[min]);
}
}

template <typename quick>
//code from lecture slides
int Partition(vector <quick> numbers, int i, int k) {
    int l;
    int h;
    int midpoint;
    quick pivot;
    quick temp;
    bool done;

    /* Pick middle element as pivot */
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    done = false;
    l = i;
    h = k;

    while (!done) {

        /* Increment l while numbers[l] < pivot */
        while (numbers[l] < pivot) {
            ++l;
        }

        /* Decrement h while pivot < numbers[h] */
        while (pivot < numbers[h]) {
            --h;
        }

        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        }
        else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}

template <typename quick>
//code from lecture slides
void Quicksort(vector <quick>numbers, int i, int k) {
    int j;

    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }

    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(numbers, i, k);

    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    Quicksort(numbers, i, j);
    Quicksort(numbers, j + 1, k);
}


int main() {


        //create fstream object to read input from the csv file
        ifstream input;

        //open file
        input.open("gun.csv");

        //check if it was properly opened
        if (!input.is_open()) {
            cout << "Input file is not opened." << endl;
            return 1;
        }


    //size of input for testing algorithms
    cout << "Enter input size to be tested:" << endl;
        int j;
        cin >> j;
        int value = j;

        //confirm to user value that will be used
        cout <<"Value tested is: " << value << endl;


        //create a vector of class Data data type
        vector<Data> dataV;

        //for loop to create a Data object for each
        //the number of objects is based on the input size entered by the user
        for (int i = 0; i < value; i++) {

            //clear input
            input.clear();

            //create Data object in which will be stored the data read from the csv file
            Data objToGetInput;
            //string that will be later converted into an integer value
            string id;
            //interger in which the value from the string above will be inserted
            int j;

            //read ID value  from dataset
            getline(input, id, ',');
            //convert string into integer
            istringstream(id) >> j;
            objToGetInput.id = j;
            input.clear();

            //read date from dataset
            getline(input, objToGetInput.date, ',');
            input.clear();

            //read state from dataset
            getline(input, objToGetInput.state, ',');
            input.clear();

            //read city or county from dataset
            getline(input, objToGetInput.cityOrCounty, ',');
            input.clear();

            //read the number of people killed from the dataset
            string killed;
            int k;
            getline(input, killed, ',');
            //convert that data obtained in form of string into an integer variable
            istringstream(killed) >> k;
            objToGetInput.numberOfKilled = k;
            input.clear();

            //read the number of people injured from dataset
            string injured;
            int z;
            getline(input, injured, ',');
            //convert that data obtained in form of string into an integer variable
            istringstream(injured) >> z;
            objToGetInput.numberOfInjured = z;
            input.clear();

            //read latitude from dataset
            string latitude;
            double l;
            getline(input, latitude, ',');
            //convert that data obtained in form of string into an integer variable
            istringstream(latitude) >> l;
            objToGetInput.latitude = l;
            input.clear();

            //read longitude from dataset
            string longitude;
            double m;
            getline(input, longitude);
            //convert that data obtained in form of string into an integer variable
            istringstream(longitude) >> m;
            objToGetInput.longitude = m;
            input.clear();

            //push the Data object into the vector of Data type
            dataV.push_back(objToGetInput);
        }

        //close input file
        input.close();

        //Creates 4 copies of dataV called dataV_B, dataV_S, dataV_Q, dataV_M.

        vector<Data> dataV_B; // for Bubblesort
        vector<Data> dataV_S; // for SelectionSort
        vector<Data> dataV_Q; // for QuickSort
        vector<Data> dataV_M; // for MergeSort

        // initialize all vectors of Data type with the same (unsorted) content from vector dataV
        dataV_B = dataV;
        dataV_S = dataV;
        dataV_Q = dataV;
        dataV_M = dataV;


        //Populates a vector with random integers (intV).

        vector<int> intV;

        srand(time(0));

        for (int i = 0; i < value; i++) {

            int a = rand() % 100000; //get random integers to be inserted in the vector
            intV.push_back(a); //add variable to the vector

        }

    //Creates 4 copies of intV called intV_B, intV_S, intV_Q, intV_M.
        vector<int> intV_B;
        vector<int> intV_S;
        vector<int> intV_Q;
        vector<int> intV_M;

        //copy the content from intV into the newly created 4 vectors
        intV_B = intV;
        intV_S = intV;
        intV_Q = intV;
        intV_M = intV;

        int p = intV.size();

        //create fstream file to print the performance of each algorithm
        ofstream output;
        output.open("recordCompileTime.txt", ios::app);

        if (!output.is_open()) {
            cout << "Failed to open output file." << endl;
            return 1;
        }
        output << "Testing with: " << value << endl;

        //PERFORMING BUBBLESORT ALGORITHM

        //sort for the first time vector with integers using Bubblesort
        clock_t start_bubbleSortInt = clock();
        bubblesort<int>(intV_B, p);
        clock_t end_bubbleSortInt = clock();
        //get performance time
        double elapsed_bubbleSortINT = double(end_bubbleSortInt - start_bubbleSortInt) / CLOCKS_PER_SEC;
        output << "BubbleSort time int: " << elapsed_bubbleSortINT << endl;

        //Resorting sorted vector using Bubblesort
        clock_t start_bubbleSortIntII = clock();
        bubblesort<int>(intV_B, p);
        clock_t end_bubbleSortIntII = clock();
        //get performance time
          double elapsed_bubbleSortINTII = double(end_bubbleSortIntII - start_bubbleSortIntII) / CLOCKS_PER_SEC;
        output << "Resorting sorted vector with int using bubblesort: " << elapsed_bubbleSortINTII << endl;

        //sort for the first time vector with Data objects using Bubblesort
        clock_t start_bubbleSortData = clock();
        bubblesort<Data>(dataV_B, p);
        clock_t end_bubbleSortData = clock();
        //get performance time
        double elapsed_bubbleSortDATA = double(end_bubbleSortData - start_bubbleSortData) / CLOCKS_PER_SEC;
        output << "BubbleSort time data: " << elapsed_bubbleSortDATA << endl;

        //Resorting sorted vector with Data objects using Bubblesort
        clock_t start_bubbleSortDataII = clock();
        bubblesort<Data>(dataV_B, p);
        clock_t end_bubbleSortDataII = clock();
        //get performance time
        double elapsed_bubbleSortDATAII = double(end_bubbleSortDataII - start_bubbleSortDataII) / CLOCKS_PER_SEC;
        output << "Resorting sorted vector with data using bubblesort: " << elapsed_bubbleSortDATAII << endl;

        //PERFORMING MERGESORT ALGORITHM

        //sort for the first time vector with integers using MergeSort
        clock_t start_mergeSortInt = clock();
        MergeSort(intV_M, 0, intV_M.size() - 1);
        clock_t end_mergeSortInt = clock();
        //get performance time
        double elapsed_mergeSortINT = double(end_mergeSortInt - start_mergeSortInt) / CLOCKS_PER_SEC;
        output << "MergeSort time int: " << elapsed_mergeSortINT << endl;

        //resorting sorted vector with integers using MergeSort
        clock_t start_mergeSortIntII = clock();
        MergeSort(intV_M, 0, intV_M.size() - 1);
        clock_t end_mergeSortIntII = clock();
        //get performance time
         double elapsed_mergeSortINTII = double(end_mergeSortIntII - start_mergeSortIntII) / CLOCKS_PER_SEC;
        output << "Resorting sorted vector with integers using mergesort: " << elapsed_mergeSortINTII << endl;

        //sort for the first time vector with Data objects using MergeSort
        clock_t start_mergeSortData = clock();
        MergeSort(dataV_M, 0, dataV_M.size() - 1);
        clock_t end_mergeSortData = clock();
         //get performance time
         double elapsed_mergeSortDATA = double(end_mergeSortData - start_mergeSortData) / CLOCKS_PER_SEC;
        output << "MergeSort time data: " << elapsed_mergeSortDATA << endl;

        //Resorting sorted vector with Data object using MergeSort
        clock_t start_mergeSortDataII = clock();
        MergeSort(dataV_M, 0, dataV_M.size() - 1);
        clock_t end_mergeSortDataII = clock();
        //get performance time
        double elapsed_mergeSortDATAII = double(end_mergeSortDataII - start_mergeSortDataII) / CLOCKS_PER_SEC;
        output << "Resorting sorted vector with data using mergesort: " << elapsed_mergeSortDATAII << endl;

        //PERFORMING SELECTION SORT ALGORITHM

        //sort for the first time vector with integers using Selection sort
        clock_t start_MinSortInt = clock();
        MinSort(intV_S, intV_S.size());
        clock_t end_MinSortInt = clock();
        //get performance time
        double elapsed_MinSortINT = double(end_MinSortInt - start_MinSortInt) / CLOCKS_PER_SEC;
        output << "SelectionSort time int: " << elapsed_MinSortINT << endl;

        //resorting sorted vector with integers using Selection sort
        clock_t start_MinSortIntII = clock();
        MinSort(intV_S, intV_S.size());
        clock_t end_MinSortIntII = clock();
         //get performance time
         double elapsed_MinSortINTII = double(end_MinSortIntII - start_MinSortIntII) / CLOCKS_PER_SEC;
        output << "Resorting vector int: " << elapsed_MinSortINTII << endl;


        //sort for the first time vector with Data objects using Selection sort
        clock_t start_MinSortData = clock();
        MinSort(dataV_S, dataV_S.size());
        clock_t end_MinSortData = clock();
          //get performance time
         double elapsed_MinSortDATA = double(end_MinSortData - start_MinSortData) / CLOCKS_PER_SEC;
        output << "Selection sort time with data: " << elapsed_MinSortDATA << endl;

        //Resorting sorted vector with Data objects using Selection sort
        clock_t start_MinSortDataII = clock();
        MinSort(dataV_S, dataV_S.size());
        clock_t end_MinSortDataII = clock();
         //get performance time
         double elapsed_MinSortDATAII = double(end_MinSortDataII - start_MinSortDataII) / CLOCKS_PER_SEC;
        output << "Resorting sorted vector with data: " << elapsed_MinSortDATAII << endl;

        //PERFORMING QUICKSORT ALGORITHM

        //sort for the first time vector with integers using Quicksort
        clock_t start_QuickInt = clock();
        Quicksort(dataV_Q, 0, dataV.size() - 1);
        clock_t end_QuickInt = clock();
        //get performance time
         double elapsed_QuickINT = double(end_QuickInt - start_QuickInt) / CLOCKS_PER_SEC;
        output << "QuickSort time int: " << elapsed_QuickINT << endl;

        //resorting sorted vector with integers using Quicksort
        clock_t start_QuickIntII = clock();
        Quicksort(dataV_Q, 0, dataV.size() - 1);
        clock_t end_QuickIntII = clock();
       //get performance time
        double elapsed_QuickINTII = double(end_QuickIntII - start_QuickIntII) / CLOCKS_PER_SEC;
        output << "Resorting sorted vector with  int: " << elapsed_QuickINTII << endl;

        //sort for the first time vector with Data objects using Quicksort
        clock_t start_QuickData = clock();
        Quicksort(intV_Q, 0, intV_Q.size() - 1);
        clock_t end_QuickData = clock();
      //get performance time
        double elapsed_QuickDATA = double(end_QuickData - start_QuickData) / CLOCKS_PER_SEC;
        output << "QuickSort time Data: " << elapsed_QuickDATA << endl << endl;

        //resorting sorted vector with Data objects using Quicksort
        clock_t start_QuickDataII = clock();
        Quicksort(intV_Q, 0, intV_Q.size() - 1);
        clock_t end_QuickDataII = clock();
         //get performance time
        double elapsed_QuickDATAII = double(end_QuickDataII - start_QuickDataII) / CLOCKS_PER_SEC;
        output << "Resorting time Data: " << elapsed_QuickDATAII << endl << endl;

        //close output file
        output.close();

        //end program

    return 0;
}