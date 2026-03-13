import readline from "node:readline/promises";
import {stdin as input, stdout as output} from "node:process";

const rl=readline.createInterface({input,output});

function calcular(a:number,b:string,c:number){
    if(b=="+")return a+c;
    if(b=='-')return a-c;
    if(b=="*")return a*c;
    if(b=="/")return a/c;
    return "ERROR";
}

const num1=await rl.question("Ingresa num1: ");
const op=await rl.queston("Ingresa el operador: ");
const num2=await rl.question("Ingresa num2: ");

console.log(`El resultado es ${calcular(num1,op,num2)}`);
rl.close()