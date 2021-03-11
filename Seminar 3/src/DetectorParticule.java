public class DetectorParticule {


    public DetectorParticule(Particula[] colectieParticule, int nrParticule) {
        this.colectieParticule = colectieParticule;
        this.nrParticule = nrParticule;
    }

    public Particula[] getColectieParticule() {
        return colectieParticule;
    }

    public void setColectieParticule(Particula[] colectieParticule) {
        this.colectieParticule = colectieParticule;
    }

    public int getNrParticule() {
        return nrParticule;
    }

    int nrParticule;

    public void setNrParticule(int nrParticule) {
        this.nrParticule = nrParticule;
    }

    public void setParticula(Particula p, int index) {

    }

    Particula[] colectieParticule;
    public Particula getParticula(int index) {
        if (index>=0 && index<colectieParticule.length) {
            return colectieParticule[index];
        }

        return null;
    }

    // TO DO - lucru cu un masiv de obiecte de tip Particula si ParticulaAtomica
}
