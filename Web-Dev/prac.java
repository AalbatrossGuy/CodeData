import java.util.Scanner;

class prac{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    String eq = sc.nextLine();
    eq = eq.replace(' ', '');
    char[] ab = eq.toCharArray();
    for (char ch: ab){
      System.out.println(ch);
    }
    // for (int i=0; i<eq.length();i++){
    //   System.out.println(eq.charAt(i));
    // }
  }
}
