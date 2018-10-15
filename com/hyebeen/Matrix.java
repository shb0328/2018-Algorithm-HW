package com.hyebeen;

public class Matrix {
    private int[] matrix;
    private int n;

    public Matrix(int n) //n by n matrix
    {
        this.n = n;
        matrix = new int[n*n];
        for(int i = 0;i<n*n; ++i) matrix[i] = i;
    }

    public Matrix(int n, int[] matrix)
    {
        this(n);
        this.matrix = matrix;
    }

    public int size() { return n*n; }
    public int dimension() { return n; }

    public Matrix minus()
    {
        Matrix result = new Matrix(this.dimension());
        for(int i =0;i<this.size(); ++i)
            result.matrix[i] = this.matrix[i] * (-1);
        return result;
    }
    public Matrix sum(Matrix A)
    {
        Matrix result = new Matrix(this.dimension());
        for(int i = 0; i<result.size() ; ++i)
            result.matrix[i] = this.matrix[i] + A.matrix[i];
        return result;
    }
    public void print()
    {
        for (int i = 0; i<this.size(); ++i) {
            System.out.print(this.matrix[i]+" ");
            if(i%this.dimension() == this.dimension() -1) System.out.println();
        }
        System.out.println();
    }

    public Matrix Strassen(Matrix B) {
        Matrix result = new Matrix(this.dimension());
        if(this.dimension() <= 1)
            result.matrix[0] = this.matrix[0] * B.matrix[0];
        else
        {
            Matrix a11 = this.partition(0,0);
            Matrix a12 = this.partition(0,1);
            Matrix a21 = this.partition(1,0);
            Matrix a22 = this.partition(1,1);

            Matrix b11 = B.partition(0,0);
            Matrix b12 = B.partition(0,1);
            Matrix b21 = B.partition(1,0);
            Matrix b22 = B.partition(1,1);

            Matrix m1 = a11.sum(a22).Strassen(b11.sum(b22));
            Matrix m2 = a21.sum(a22).Strassen(b11);
            Matrix m3 = a11.Strassen(b12.sum(b22.minus()));
            Matrix m4 = a22.Strassen(b21.sum(b11.minus()));
            Matrix m5 = a11.sum(a12).Strassen(b22);
            Matrix m6 = a21.sum(a11.minus()).Strassen(b11.sum(b12));
            Matrix m7 = a12.sum(a22.minus()).Strassen(b21.sum(b22));

            result = merge(result.dimension(),
                    m1.sum(m4).sum(m5.minus()).sum(m7),
                    m3.sum(m5),
                    m2.sum(m4),
                    m1.sum(m2.minus()).sum(m3).sum(m6)
            );
        }
        return result;
    }

    private Matrix partition(int i, int j)
    {
        int n = this.dimension()/2;
        Matrix result = new Matrix(n);

        int index = 0;
        for(int row = i*this.size()/2 ; row < i*this.size()/2+this.size()/2; row+=this.dimension())
        {
            for(int col = row+j*n ; col < row+j*n+n ; ++col)
                result.matrix[index++] = this.matrix[col];
        }
        return result;
    }

    private Matrix merge(int n, Matrix C11, Matrix C12, Matrix C21, Matrix C22)
    {
        Matrix C = new Matrix(n);
        int i = 0;
        int i11=0,i12=0,i21=0,i22=0;
        while (i<C.size())
        {
            if(i<C.size()/2 && i%n < n/2) C.matrix[i] = C11.matrix[i11++];
            else if(i<C.size()/2 && i%n >= n/2) C.matrix[i] = C12.matrix[i12++];
            else if(i>=C.size()/2 && i%n < n/2) C.matrix[i] = C21.matrix[i21++];
            else C.matrix[i] = C22.matrix[i22++];
            ++i;
        }
        return C;
    }
}
