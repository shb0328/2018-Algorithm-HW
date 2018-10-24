package com.hyebeen;

public class SampleValue2 {
    public static void main(String[] args) {
        int n = 4;
        int[] a = {0,3,2,8,1,0,0,4,5,30,5,5,1,2,3,4};
        int[] b = {1,1,0,11,2,0,0,2,1,2,1,2,0,28,0,7};
        Matrix A = new Matrix(n,a);
        System.out.println("A = ");A.print();
        Matrix B = new Matrix(n,b);
        System.out.println("B = ");B.print();
        System.out.println();

        Matrix C = A.Strassen(B);
        System.out.println("A x B = ");C.print();
    }
}
