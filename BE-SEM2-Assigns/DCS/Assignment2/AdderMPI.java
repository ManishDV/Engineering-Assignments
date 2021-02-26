import mpi.*;
import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class AdderMPI {

	public static void main(String[] args) throws Exception{
		
		MPI.Init(args);
		int rank = MPI.COMM_WORLD.Rank();
		int size = MPI.COMM_WORLD.Size();
        int [] input1 = new int [10000000];
        int share = input1.length/size;
		int root=0;
		int receive[] = new int[share];
		int  collect[] = new int[size];
		long start = System.currentTimeMillis();
        
        if(root==rank){
			// Scanner scanner = new Scanner(new File("input.txt"));
            Random r = new Random();
            int i = 0;
            int range = 100;
            while(i < 10000000)
            {
                input1[i++] = r.nextInt(range);
            }
		}
		

		MPI.COMM_WORLD.Scatter(input1,0,share,MPI.INT,receive,0,share,MPI.INT,root);
        BigInteger ans = new BigInteger("0");
        BigInteger Final_Ans = new BigInteger("0");

        for(int i = 0; i < share; i++){
            ans = ans.add(BigInteger.valueOf(receive[i]));
        }
        
        int gather[] = new int[1];
        gather[0] = ans.intValue();

		MPI.COMM_WORLD.Gather(gather,0,1,MPI.INT,collect,0,1,MPI.INT,root);
		
		if(rank==root){
            
            for(int i = 0; i < size; i++){
                Final_Ans = Final_Ans.add(BigInteger.valueOf(collect[i]));
            }

            System.out.println("\nAddition of 1L Elements : " + Final_Ans.toString() + "\n");
            long end = System.currentTimeMillis();
            float sec = (end - start) / 1000F; 
            System.out.println("\n\nTime Taken: " + sec + " seconds");    
            
		}	
		MPI.Finalize();
		return;		
	}
}
