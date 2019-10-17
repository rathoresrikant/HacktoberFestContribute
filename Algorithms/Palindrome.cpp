bool checkPalindrome(std::string inputString) {
    bool a=true;
    int b=inputString.length();
    if(b!=1){
    for(int i = 0;i < inputString.length()/2 ; ++i){
        if(inputString[i]==inputString[b-1]){
            a=true;
        }else{
            a=false;
         }
        b--;
    }
    }
    return a;
}