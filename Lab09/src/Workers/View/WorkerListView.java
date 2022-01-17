package Workers.View;



public class WorkerListView
{
    public void printDirector(String pesel, String name, String surname, String salary, String jobsPhoneNumber, String bonusMoney,
                              String jobsCardNumber, String costLimit, String position)
    {
        System.out.println(
                "Identyfikator PESEL:  " + pesel + "\n" +
                "Imie:  " + name + "\n"  +
                "Nazwisko:  "  + surname + "\n"   +
                "Stanowisko  " + position  + "\n"  +
                "Wynagrodzenie (zl):  " + salary + "\n" +
                "Telefon Sluzbowy numer:  " + jobsPhoneNumber + "\n" +
                "Dodatek sluzbowy (zl):  " + bonusMoney + "\n" +
                "Karta sluzbowa numer:  " + jobsCardNumber + "\n" +
                "Limit kosztow/miesiac(zl):  " + costLimit + "\n" +

                "[Enter] - nastepny"
        );
    }
    public void printSalesMan(String pesel, String name, String surname, String salary, String jobsPhoneNumber, String provision,
                              String provisionLimit,String position)
    {
        System.out.println(
                "Identyfikator PESEL:  " + pesel + "\n" +
                        "Imie:  " + name + "\n"  +
                        "Nazwisko:  "  + surname + "\n"   +
                        "Stanowisko  " + position  + "\n"  +
                        "Wynagrodzenie (zl):  " + salary + "\n" +
                        "Telefon Sluzbowy numer:  " + jobsPhoneNumber + "\n" +
                        "Prowizja (%):  " + provision + "\n" +
                        "Limit prowizji/miesiac(zl):  " + provisionLimit + "\n" +

                        "[Enter] - nastepny"
        );
    }
    public void menuFormat()
    {
        System.out.println(
                "1. Lista Pracownikow\n" +
                "2. Dodaj pracownika\n"  +
                "3. Usun pracownika\n"   +
                "4. Kopia zapasowa"
        );
    }
    public void addDirector(String pesel, String name, String surname, String salary, String jobsPhoneNumber, String bonusMoney,
                            String jobsCardNumber, String costLimit, String position)
    {
        System.out.println(
                        "Dodaj Dyrektora\n" +
                        "Identyfikator PESEL:  " + pesel + "\n" +
                        "Imie:  " + name + "\n"  +
                        "Nazwisko:  "  + surname + "\n"   +
                        "Stanowisko  " + position  + "\n"  +
                        "Wynagrodzenie (zl):  " + salary + "\n" +
                        "Telefon Sluzbowy numer:  " + jobsPhoneNumber + "\n" +
                        "Dodatek sluzbowy (zl):  " + bonusMoney + "\n" +
                        "Karta sluzbowa numer:  " + jobsCardNumber + "\n" +
                        "Limit kosztow/miesiac(zl):  " + costLimit + "\n" +

                        "[Enter] - nastepny"
        );
    }
    public void addSalesMan(String pesel, String name, String surname, String salary, String jobsPhoneNumber, String provision,
                            String provisionLimit,String position)
    {
        System.out.println(
                        "Dodaj pracownika\n " +
                        "Identyfikator PESEL:  " + pesel + "\n" +
                        "Imie:  " + name + "\n"  +
                        "Nazwisko:  "  + surname + "\n"   +
                        "Stanowisko  " + position  + "\n"  +
                        "Wynagrodzenie (zl):  " + salary + "\n" +
                        "Telefon Sluzbowy numer:  " + jobsPhoneNumber + "\n" +
                        "Prowizja (%):  " + provision + "\n" +
                        "Limit prowizji/miesiac(zl):  " + provisionLimit + "\n" +

                        "[Enter] - nastepny"
        );
    }
    public void deleteSalesMan(String pesel, String name, String surname, String salary, String jobsPhoneNumber, String provision,
                               String provisionLimit,String position)
    {
        System.out.println(
                "Usun pracownika\n " +
                        "Identyfikator PESEL:  " + pesel + "\n" +
                        "Imie:  " + name + "\n"  +
                        "Nazwisko:  "  + surname + "\n"   +
                        "Stanowisko  " + position  + "\n"  +
                        "Wynagrodzenie (zl):  " + salary + "\n" +
                        "Telefon Sluzbowy numer:  " + jobsPhoneNumber + "\n" +
                        "Prowizja (%):  " + provision + "\n" +
                        "Limit prowizji/miesiac(zl):  " + provisionLimit + "\n" +
                        "[Enter] - nastepny"
        );
    }
    public void delDirector(String pesel, String name, String surname, String salary, String jobsPhoneNumber, String bonusMoney,
                            String jobsCardNumber, String costLimit, String position)
    {
        System.out.println(
                        "Usun Dyrektora\n" +
                        "Identyfikator PESEL:  " + pesel + "\n" +
                        "Imie:  " + name + "\n"  +
                        "Nazwisko:  "  + surname + "\n"   +
                        "Stanowisko  " + position  + "\n"  +
                        "Wynagrodzenie (zl):  " + salary + "\n" +
                        "Telefon Sluzbowy numer:  " + jobsPhoneNumber + "\n" +
                        "Dodatek sluzbowy (zl):  " + bonusMoney + "\n" +
                        "Karta sluzbowa numer:  " + jobsCardNumber + "\n" +
                        "Limit kosztow/miesiac(zl):  " + costLimit + "\n" +

                        "[Enter] - nastepny"
        );
    }

    public void Error()
    {
        System.out.println("Najprawdopodobniej nieznana przyczyna problemow");
    }
}


