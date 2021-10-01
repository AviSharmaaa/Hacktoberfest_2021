public class Test{
    public static void main(String[] args) {
        int[] data = {50, 40, 20, 5, 100, 43};
        int largest;

        largest = data[4];
        for(int i = 1; i < 6; i++)
            if(data[i] > largest)
                largest = data[i];

        System.out.print("The largest number = "+largest);
}
}
