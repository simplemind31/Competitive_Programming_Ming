import readline from "node:readline/promises"
import {stdin as input, stdout as output} from "node:process"

const rl = readline.createInterface({input,output})

const nombre=await rl.question("Ingresa tu nombre: ")
const apellido=await rl.question("Ingresa tu apellido: ")
console.log("Tu nombre es: "+nombre)
console.log("Tu apellido es: "+apellido)
rl.close()
