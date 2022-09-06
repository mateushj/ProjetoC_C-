#include <stdio.h>

int main(void)
{
    float num1,num2,res=0;
    char oper;
    printf("Calculadora:\n");       
	
	        scanf("%f", &num1);
            scanf(" %c",&oper);
            scanf("%f",&num2);
            switch( oper ) {
                case '+':
                       res=num1+num2;
                       break;
			    case '-':
                       res= num1 - num2;
                       break;
                case '*':
                       res= num1 * num2;
                       break;
				case '/':
                    res=num1 / num2;
                    break;
                case '=':
                	printf("Resultado = %.2f\n",num1);
                	break;  
			}
		
			do{
	        scanf(" %c",&oper);
            scanf("%f",&num2);
            switch( oper ) {
                case '+':
                       res=res+num2;
                       break;
				case '-':
                       res= res - num2;
                       break;
                case '*':
                       res= res * num2;
                       break;
				case '/':
                    res=res / num2;
                    break;
                case '=':
                	printf("Resultado = %.2f\n",res);
                	break;  
			}
		}while(oper != '=');
}

        
      
