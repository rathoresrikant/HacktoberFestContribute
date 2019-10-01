#include <iostream>
#include <iterator>

long int* i_tsearch(long int *first, long int *last, long int value, long int& counter) {
    long int *news = last;                          //Constant pointer to beyond my original array size.
    while(first < last) {
        counter++;
        long int t1_marker = (last-first)/3;        //Index to the end of the first third from my array.
        auto m1 = first+t1_marker;                  //Memory address to the first third of the current array.

        long int t2_marker = 2*(last-first)/3;      //Index to the end of the second third from my array.
        auto m2 = first+t2_marker;                  //Address to the second third of the current array.
        counter += 4;
        if(value == *m1) {
            counter++;
            return m1; //Element found.
        }
        else if(value == *m2) {
            counter += 2;
            return m2; //Element found.
        }
        else {
            counter += 2;
            if(value < *m1) {
                last = m1;
                counter += 2;
            }
            else if(value < *m2) {
                first = m1+1;
                last = m2;
                counter += 4;
            }
            else {
                first = m2+1;
                counter += 3;
            }
        }
    }
    return news; //Element not found.
}

long int* r_tsearch(long int *first, long int *last, long int value, long int& counter) {
    counter++;
    if(first < last) {
        counter++;
        long int t1_marker = (last-first)/3;           //Index to the end of the first third from array.
        auto m1 = first+t1_marker;                     //Address to the end of first third of my array.

        long int t2_marker = 2*(last-first)/3;         //Index to the end of the second third from array.
        auto m2 = first+t2_marker;                     //Address to the end of second third of the current array.
        counter += 4;
        if(value == *m1) {
            counter++;
            return m1; //Element found.
        }
        else if(value == *m2) {
            counter += 2;
            return m2; //Element found.
        }
        else {
            counter += 2;
            if(value < *m1) {
                counter++;
                auto s = r_tsearch(first, m1-1, value, counter);
                counter++;
                /*
                Checks if the found memory address really refers to our value.
                If it does, return it, otherwise, return outside the array.
                */
                if(value == *s) {
                    counter++;
                    return s; //Element found.
                }
                else {
                    counter++;
                    return last; //Element not found.
                }
            }
            else if(value < *m2) {
                counter += 2;
                auto l = r_tsearch(m1+1, m2-1, value, counter);
                counter++;
                /*
                Checks if the found memory address really refers to or value.
                If it does, return it, otherwise, return outside the array.
                */
                if(value == *l) {
                    counter++;
                    return l; //Element found.
                }
                else {
                    counter++;
                    return last;//Element not found.
                }
            }
            else {
                counter += 2;
                return r_tsearch(m2+1, last, value, counter);
            }
        }
    }
    return last; //Element not found.
}

int main()
{
    int A[]{1,4,7,10,13,16,19,20,28,31};
    int B[]{8,12,16,20,24,28,40,49};
    
    int key = 20, success = 0;
    int counter_rec = 0, counter_iter = 0;
    
    auto res_iter = i_tsearch(std::begin(A), std:end(A), key, counter_iter);
    auto res_recur = r_tsearch(std::begin(B), std:end(B), key, counter_rec);
    
    if (res_iter != std::end(A)){
        std::cout << "Found " << *res_iter << " at pos A[" << std::distance(std::begin(B), res_iter)
                  << "], with " << counter_iter << " iterations.\n";
        success++;
    } else {
        std::cout << "Failed to find '" << key << "'\n";
    }  
        
    if (res_recur != std::end(B)){
        std::cout << "Found " << *res_recur << " at pos A[" << std::distance(std::begin(B), res_recur)
                  << "], with " << counter_rec << " iterations.\n";
        success++;
    } else {
        std::cout << "Failed to find '" << key << "'\n";
    }
    
    if(success == 2)
    {
        std::cout << "Searchs are working!!\n";
    }
    
    return 0;    
}
