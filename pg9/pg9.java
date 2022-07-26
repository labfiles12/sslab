package Program9;

import java.util.Scanner;

public class pg9 {
    static void logic(boolean fifoCheck) { // fifoCheck = true means fifo else it is lru
        Scanner s = new Scanner(System.in);
        
        System.out.println("Enter no. of frames & input string");
        int noFrames = s.nextInt();
        String input = s.next();
        
        char[] frames = new char[noFrames];
        int curr = 0; 
        int[] usage = new int[noFrames]; 
        for (int i = 0; i < noFrames; i++) 
            usage[i] = -1; 
        int pageFaults = 0;
        
        boolean checkFault;
        
        for (int i = 0; i < input.length(); i++) 
        {
            checkFault = true;
            for (int j = 0; j < noFrames; j++) 
            {
                if (frames[j] == input.charAt(i)) 
                {
                    checkFault = false;
                    if (!fifoCheck)
                        usage[j] = i;
                }
            }
            if (checkFault) 
            {
                pageFaults++;
                if (fifoCheck) 
                {
                    frames[curr] = input.charAt(i);
                    curr = (curr + 1) % noFrames;
                } 
                else 
                {
                    int smallestVal = Integer.MAX_VALUE, smallestIndex = 0;
                    for (int j = 0; j < noFrames; j++) 
                    {
                        if (usage[j] < smallestVal) 
                        {
                            smallestIndex = j;
                            smallestVal = usage[j];
                        }
                    }
                    frames[smallestIndex] = input.charAt(i);
                    usage[smallestIndex] = i;
                }
            }
            for (int j = 0; j < noFrames; j++) {
                System.out.print(frames[j] + "\t");
            }
            System.out.println();
        }
        System.out.println("PageFaults: " + pageFaults);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        for (;;) {
            System.out.println("\n1.FIFO\n2.LRU\n3.EXIT");
            int choice = s.nextInt();
            switch (choice) {
                case 3:
                    return;
                case 1:
                    logic(true);
                    break;
                case 2:
                    logic(false);
                    break;
            }
        }
    }
}
