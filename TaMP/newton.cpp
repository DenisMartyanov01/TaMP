double Task1::newton(double A)
{
    double K = 1;
    K += A / K;
    double Kold;
    do
    {
        Kold = K;
        K = (A / K + K) / 2.0;
    } while (abs(Kold - K) > 1e-10);

    return K;
}