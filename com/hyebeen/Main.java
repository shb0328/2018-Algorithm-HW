package com.hyebeen;

public class Main {

    public static void main(String[] args) {
        int n = 2;
	    Matrix A = new Matrix(n);
	    A.println();
	    Matrix B = new Matrix(n);
	    B.println();
	    Matrix C = A.Strassen(B);
	    C.println();
    }
}
