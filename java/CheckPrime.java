import java.util.Scanner;
class CheckPrime
{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		
		if(isPrime(n))
		    System.out.println(n + " is prime number");          // if prime
		else
		    System.out.println(n + " is not a prime number");    // if not prime
		
	}
	// Method to check a number is prime or not
	static boolean isPrime(int n) { 
        if (n <= 1)                       // 1 is not a prime number
            return false; 
        if (n <= 3)                       // 2 and 3 are prime numbers
            return true;                  
        if (n % 2 == 0 || n % 3 == 0)     // Multiple of 2 and 3 will not be prime
            return false; 
        
        for (int i = 5; i * i <= n; i = i + 6)     // Now we have to only check that 
            if (n % i == 0 || n % (i + 2) == 0)    // number should not be multiple of 6 (-,+) 1
            	return false; 
            	
        return true; 
    }
}
