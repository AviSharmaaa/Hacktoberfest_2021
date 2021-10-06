import java.util.regex.*;
import java.util.Scanner;

public class PasswordValidator {
    // Function to validate the user's password.
    public static boolean isValidPassword(String pwd) {

        //regex expresssion to check whether the password is valid
        String regex = "^(?=.*[0-9])" + "(?=.*[a-z])(?=.*[A-Z])" + "(?=.*[@#$%^&+=])" + "(?=\\S+$).{8,20}$";

        Pattern p = Pattern.compile(regex);
       
        if (pwd == null) {
            return false;
        }
        
         
        Matcher m = p.matcher(pwd);

        return m.matches();
    }

    public static void main(String args[]) {

        System.out.println(
                "\n\n\t\t================================= PASSWORD VALIDATION =================================\n\n");

        Scanner scan = new Scanner(System.in);

        String opt;
        
        // To accept the user's password
        do {
            System.out.print("\t\tEnter Your Password: ");

            String password = scan.nextLine();

            System.out.println("\t\tYour Password: " + password);

            System.out.println("");

            if (isValidPassword(password)) {
                System.out.println("\t\tKudos!! You created a Valid Password !!!");
            } else {
                System.out.println("\t\tOops... Your passoword is not Valid!! Please create another password");
            }

            System.out.println("");

            System.out.print("\t\tDo you want to continue..  (Yes/No) :");
            opt = scan.nextLine();
            System.out.println("");

        } while (opt.equals("Yes"));

    }
}
