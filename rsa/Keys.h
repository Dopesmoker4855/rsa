
struct Private_Key
{
    int N;
    int D;
};
struct Public_Key
{
    int N;
    int E;
};
class Keys
{
    private:
        Private_Key private_key;
        Public_Key public_key;
    public:
        void setKey_N(int N){
            private_key.N = N;
            public_key.N = N;
        }
        void setPrivateKey_D(int D){
            private_key.D = D;
        }
        void setPublicKey_E(int E){
            public_key.E = E;
        }
        int getKey_N(){
            return public_key.N;
        }
        int getPrivateKey_D(){
            return private_key.D;
        }
        int getPublicKey_E(){
            return public_key.E;
        }
        double getDoublePublicKey_E(){
            return (double)getPublicKey_E();
        }
        double getDoubleKey_N(){
            return (double)getKey_N();
        }
};
