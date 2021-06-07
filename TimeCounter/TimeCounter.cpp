#include "Counter.cpp"

#include<vector>
#include<algorithm>

int main()
{

    // example how to use:
    using namespace timer;
    TimeCounter c;
    std::vector<int> data(10000); // creating a vector with elements from 0 to 9999
    for (int i = 0; i < 10000; i++)  data[i] = i;
    std::random_shuffle(data.begin(),data.end()); // rearranging order so that get random sequence
    c.SetCounter(); // start counting time 
    std::sort(data.begin(),data.end()); // as an exmaple use std::sort() algorithm to sort the vector
    c.StopCounter(); // stop counter 
    std::cout << "time takes to sort 10000 integer array is " << c.getTime() << " milliseconds\n\n"; // displaying the number of milliseconds it took to sort the vector


    return 0;
}
