import readline from "node:readline/promises";
import {stdin as input, stdout as output} from "node:process";

const rl=readline.createInterface({input,output});

const n=await rl.question("Itroduce n: ");
let i=1;
let par="",imp="";
// while(i<=n){
//     if(i%2==0)par=`${par} ${i},`;
//     else imp=`${imp} ${i},`;
//     i++;
// }
for(let i=0;i<=n;i++){
    
}
console.log(par)
console.log(imp)
rl.close();