// Question 1:Write a program to input any number from user and check whether the given number is perfect number or not.
// Perfect number is a positive integer which is equal to the sum of its proper positive divisors. For example:
// 6 is the first perfect number because Proper divisors of 6 are 1, 2, 3
// Sum of its proper divisors = 1 + 2 + 3 = 6.
// Hence 6 is a perfect number.
// Input Format
// Each test case contains a number.
// Output Format
// Print yes or no based on condition.
// Sample Input
// 6
// Sample Output
// yes
 
#include<iostream>
using namespace std;
void perfect(int N){
    int sum = 0;
    for(int i = 1; i <= N/2 ; i++){
        if(N % i==0){
            sum += i;
        } else {
            sum=sum;
        }  
    }
    if (N == sum){
        cout<<"yes";
        
    } else {
        cout<<"no";
    }
}
int main()
{    
    
    int N;
    cin>>N;
    perfect(N);
    return 0;
}

// Question 2: Write a program to print the n lines of the below pyramid
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// Input
// Each test case will contain a number n where n >=1.
// Output
// Print the first n lines of the above pyramid
// Sample Input
// 3
// Sample Output
// 1
// 2 3
// 4 5 6

int main()
{    
    
    int N;
    cin>>N;
    perfect(N);
   return 0;
}
using namespace std;
int main()
{    
    int n;
    cin>>n;
    int m = 1;
    for(int i = 0; i<n ; ++i){
        for(int j = 0; j<= i ; ++j){
            if (j== i){
                cout<<m++;
            } else {
                cout<<m++<<" ";
            }
        }
        cout<<endl;
    }
   return 0;
}