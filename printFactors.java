public class Main {

    public static void main(String[] args) {
        printFactors(10);
    }
    public static void printFactors(int number){
        if(number<-1){
            System.out.println("Invalid Number");
        }
        for(int n=1;n<=number;n++){
            if(number%n==0){
                System.out.println(n);
            }
        }
    }
}
