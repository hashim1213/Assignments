#include <simplecpp>

main_program{
    for(int i=1;i<=30;i++){
        if(i%3==0 && i%4==0){
            cout<<"fizzbuzz"<<endl;
        }
        else if(i%3==0){
            cout<<"fizz"<<endl;
        }
        else if(i%4==0){
            cout<<"buzz"<<endl;
        }
        else{
            cout<<i<<endl;
        }
    }
    return 0;
}
