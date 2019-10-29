
public class EnclosingEnum {

    private class Inner { }
    private class InnerA extends Inner { }
    private class InnerB extends Inner { }
    private class InnerC extends Inner { }

    enum InnerEnum {
        INNER_A {
            @Override
            public Inner getInstance() {
                return new InnerA();	//Compile Error.
            }
        },
        INNER_B {
            @Override
            public Inner getInstance() {
                //return new InnerB();
                return new EnclosingEnum.InnerB();	//Compile Error.
            }
        },
        INNER_C {
            @Override
            public Inner getInstance() {
                //return new InnerC();
                return EnclosingEnum.new InnerC();	//Compile Error.
            }
        },
        ;

        public abstract Inner getInstance();
    }

    private static class InnerFactoryEnumStyled {
        public static Inner getInner(InnerEnum inner) {
            return inner.getInstance();
        }
    }


    public static void main(String[] args) {
        System.out.println("Hello World.");

        Inner inner = InnerFactoryEnumStyled.getInner(InnerEnum.INNER_A);
   }

}
