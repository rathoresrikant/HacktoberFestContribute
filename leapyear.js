var readline = require("readline-sync");
function readYear(){
    do{
        var startYear = readline.question("Enter start year:");
        var endYear = readline.question("Enter end year:");
    }while ((startYear==0)||(startYear<0)||(endYear<startYear));
    return [startYear,endYear];  
}
function isLeapYear(year){
    if (((year%4==0)&&(year%100!=0))||(year%400==0)) {
        return true;
    } else{
        return false; 
    }
}
var x = readYear();
for (var i=0;i<=(x[1]-x[0]);i++){
    var y = isLeapYear(parseInt(x[0])+i);
    if (y == true){
        console.log(parseInt(x[0])+i,"is a leap year")
    }else{
        console.log(parseInt(x[0])+i,"is not a leap year")
    }
}