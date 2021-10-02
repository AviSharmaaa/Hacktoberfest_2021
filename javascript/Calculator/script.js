var result=" ";
function display(num){
   result=result+num;
   document.getElementById('display-panel').innerHTML= result;
}
function clearvalue(){
   document.getElementById('display-panel').innerHTML=" ";
   result=" ";
}
function calculate(){
   Num=window.result;
   document.getElementById('display-panel').innerHTML=eval(Num); 
}
