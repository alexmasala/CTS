public class UtilizareParticule {
    public static void main(String[] args) {
        Particula p1 = new Particula(1, 31);
        Particula p2 = new Particula(0, 62);

        System.out.println("hashCode pentru p1:" + p1.hashCode());
        System.out.println("hashCode pentru p2:" + p2.hashCode());

        if (p1.equals(p2)) {
            System.out.println("este aceeasi particula");
        } else {
            System.out.println("sunt particule diferite");
        }

        ParticulaAtomica pa1 = new ParticulaAtomica(3, 5, "neutron");
        System.out.println(pa1.toString());

        System.out.println("distanta dintre p1 si p2: " + ParticulaMasurabila.distantaEuclidiana(p1, p2));
        System.out.println("distanta de la pa1 la origine: " + pa1.distantaOrigine());
        System.out.println("distanta de la pa1 la p1: " + pa1.distantaPanaLa(p1));

        pa1.mutaParticula(15, 21);
        System.out.println("coordonate noi pa1: " + pa1.toString());

        pa1.spuneParticula("un text");
    }
}
