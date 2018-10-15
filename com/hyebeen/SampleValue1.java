package com.hyebeen;

public class SampleValue1 {

    public static void main(String[] args) {
        int n = 4;
        int[] a = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7};
        int[] b = {8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5};
	    Matrix A = new Matrix(n,a);
	    System.out.println("A = ");A.print();
	    Matrix B = new Matrix(n,b);
        System.out.println("B = ");B.print();
        System.out.println();

	    Matrix C = A.Strassen(B);
        System.out.println("A x B = ");C.print();
    }
}
