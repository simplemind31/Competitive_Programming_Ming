def calculadora(n1,n2,tip):
    if tip=='+':
        return n1+n2
    elif tip=='-':
        return n1-n2
    elif tip=='*':
        return n1*n2
    elif tip=="/":
        return n1/n2
    else:
        return "ERROR"
print("Calculadora sis-111")
print("*******************")
a=float(input("Introduzca el primer valor\n"))
ope=input("Introduzca el operador (+,-,*,/)\n")
b=float(input("Introduzca el segundo valor\n"))
print(calculadora(a,b,ope))
