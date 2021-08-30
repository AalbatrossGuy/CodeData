import java.io.*;
import java.util.*;
//class prac{
//    public static void main(String args[]) throws IOException{
        //System.out.println("Helo bruh world");
        //int x = 5;
        //float result = (x+3)/6;
        //float result2 = (2*x+5)/3;
        //float answer = result - result2;
        //System.out.println(answer);
        //int PRESENT = 350;
        //int ABSENT = 30;
        //int monthly_income = PRESENT*25;
        //int absent = ABSENT*5;
        //int monthlyincome = monthly_income - absent;
        //System.out.println(monthlyincome);
//        int QUESTIONS = 150;
//        int candidate1 = 80/100*QUESTIONS;
//        int candidate2 = 72/100*QUESTIONS;
//        System.out.println(candidate1+" "+candidate2);
//    }
//    }
//
class prac{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("1.Addition\n2.Substraction\n3.Multiplication\n4.Divison\n5.Remainder");
        System.out.println("Enter your choice: ");
        int ch = sc.nextInt();
        
        switch(ch){
            case 1:
                //System.out.println("Addition selected");
                System.out.println("Enter 2 numbers: ");
                int a_add = sc.nextInt();
                int b_add = sc.nextInt();
                int c_add = a_add +b_add;
                System.out.println("Answer = "+c_add);
                break;
            case 2:
                //System.out.println("Substraction selected");
                System.out.println("Enter 2 numbers: ");
                int a_sub = sc.nextInt();
                int b_sub = sc.nextInt();
                int c_sub = a_sub - b_sub;
                System.out.println("Answer = "+c_sub);
                break;
            case 3:
                System.out.println("Enter 2 numbers: ");
                int a_multi = sc.nextInt();
                int b_multi = sc.nextInt();
                int c_multi = a_multi * b_multi;
                System.out.println("Answer = "+c_multi);
                break;
            case 4:
                System.out.println("Enter 2 numbers: ");
                int a_div = sc.nextInt();
                int b_div = sc.nextInt();
                int c_div = a_div / b_div;
                System.out.println("Answer = "+c_div);
                break;
            case 5:
                System.out.println("Enter 2 numbers: ");
                int a_remain = sc.nextInt();
                int b_remain = sc.nextInt();
                int c_remain = a_remain % b_remain;
                System.out.println("Answer = "+c_remain);
                break;
            case 6:
                int c_min = Math.min(10, 30);
                System.out.println("Min Number: "+c_min);
                break;
            case 7:
                int c_max = Math.max(30, 100);
                System.out.println("Max Number: "+c_max);
                break;
            case 8:
                double c_sqrt = Math.sqrt(25);
                System.out.println("Sqrt Number: "+c_sqrt);
                break;
            case 9:
                double c_pow = Math.pow(5, 2);
                System.out.println("Pow Number: "+c_pow);
                break;
            case 10:
                double c_cbrt = Math.cbrt(27);
                System.out.println("Cube Root Number: "+c_cbrt);
                break;

            case 11:
                System.out.println("Enter 3 numbers");
                int a_num = sc.nextInt();
                int b_num = sc.nextInt();
                int c_num = scn.nextInt();

            default:
                System.out.println("Choice Doesn't Exists!!");


    
        }
    }
}
