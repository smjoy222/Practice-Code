public class possition {
    public static void main(String[] args) {
        int[] arr = {5, 3, 8, 2, 9, 1};
        
        int smallest = arr[0];
        int position = 0;
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < smallest) {
                smallest = arr[i];
                position = i;
            }
        }
        
        System.out.println("Smallest element: " + smallest);
        System.out.println("Position: " + position);
    }
}
