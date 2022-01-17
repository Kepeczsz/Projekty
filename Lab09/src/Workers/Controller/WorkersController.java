package Workers.Controller;

import Workers.Models.Director;
import Workers.Models.SalesMan;
import Workers.Models.Worker;
import Workers.Service.WorkerService;
import Workers.View.WorkerListView;

import java.io.*;
import java.util.HashMap;
import java.util.Scanner;

public  class WorkersController
{
    WorkerService service = new WorkerService();
    WorkerListView view = new WorkerListView();
    Scanner in = new Scanner(System.in);
    public void Controller() throws IOException
    {

        boolean warunek = true;
        do
        {

            view.menuFormat();
            int i = in.nextInt();
            if( i == (int)i)
            {
                in.nextLine();
                switch (i)
                {
                    case 1:
                        PrintHashMap();
                        warunek = false;
                        break;
                    case 2:
                        Insert();
                        warunek = false;
                        break;
                    case 3:
                        delete();
                        warunek = false;
                        break;
                    case 4:
                        serializacja();
                        warunek = false;
                        break;
                    default:
                        System.out.println("cos sie nie udalo, konczymy");
                        warunek = false;
                        break;
                }
            }else
            {
                view.Error();
            }

        }while(warunek == false);



    }
    public void Insert()
    {
        char wybor;
        boolean warunek = false;
        do {
            System.out.println("[D]yrektor/[H]andlowiec:\n  " +
                               "-----------------------------");
            wybor=in.nextLine().charAt(0);
              if( wybor == 'D' || wybor == 'd')
            {
                Director director = new Director();
                System.out.println("Identyfikator Pesel:  ");
                director.setPesel(in.nextLine());
                System.out.println("Imie:  ");
                director.setName(in.nextLine());
                System.out.println("Nazwisko");
                director.setSurname(in.nextLine());
                System.out.println("Wynagrodzenie");
                director.setSalary(in.nextLine());
                System.out.println("Telefon sluzbowy numer:  ");
                director.setJobsPhoneNumber(in.nextLine());
                System.out.println("Dodatek sluzbowy:  ");
                director.setBonusMoney(in.nextLine());
                System.out.println("Karta Sluzbowa numer:  ");
                director.setJobsCardNumber(in.nextLine());
                System.out.println("Limit kosztow/miesiac (zl):  ");
                director.setCostLimit(in.nextLine());

                view.addDirector(director.getPesel(),director.getName(),director.getSurname(),director.getSalary(),director.getJobsPhoneNumber(),
                                 director.getBonusMoney(), director.getJobsCardNumber(), director.getCostLimit(),director.getPosition());

                String save = in.nextLine();

                service.insertDirector(director.getPesel(),director.getName(),director.getSurname(),director.getSalary(),director.getJobsPhoneNumber(),
                        director.getBonusMoney(), director.getJobsCardNumber(), director.getCostLimit());
                warunek = true;
                break;
            }else if(wybor == 'H' || wybor ==  'H')
              {
                  SalesMan salesMan = new SalesMan();
                  System.out.println("Identyfikator Pesel:  ");
                  salesMan.setPesel(in.nextLine());

                  System.out.println("Imie:  ");
                  salesMan.setName(in.nextLine());
                  System.out.println("Nazwisko");
                  salesMan.setSurname(in.nextLine());
                  System.out.println("Wynagrodzenie");
                  salesMan.setSalary(in.nextLine());
                  System.out.println("Telefon sluzbowy numer:  ");
                  salesMan.setJobsPhoneNumber(in.nextLine());
                  System.out.println("Prowizja(%):  ");
                  salesMan.setProvision(in.nextLine());
                  System.out.println("Limit prowizji/miesiac (zl)  ");
                  salesMan.setProvisionLimit(in.nextLine());

                  view.addSalesMan(salesMan.getPesel(),salesMan.getName(),salesMan.getSurname(),
                          salesMan.getSalary(),salesMan.getJobsPhoneNumber(),salesMan.getProvision(),salesMan.getProvisionLimit(),salesMan.getPosition());
                  String save = in.nextLine();
                  service.insertSalesMan(salesMan.getPesel(), salesMan.getName(),salesMan.getSurname(),salesMan.getSalary(),
                          salesMan.getJobsPhoneNumber(),salesMan.getProvision(),salesMan.getProvisionLimit());
                  warunek = true;
                  break;
              }else
            {
                view.Error();
            }

            }while(warunek == true);
        }
    public void delete()
    {
        System.out.println("Podaj Identyfikator PESEL:  ");
        System.out.println("--------------------------------");
        String pesel = in.nextLine();
        boolean wybor = false;
        do
        {
            Worker worker = service.getWorker(pesel);
            if(worker.getClass() == Director.class)
            {
                view.delDirector(worker.getPesel(),worker.getName(),worker.getSurname(),
                        worker.getSalary(),((Director) worker).getJobsPhoneNumber(),
                        ((Director) worker).getBonusMoney(),((Director) worker).getJobsCardNumber(),
                        ((Director) worker).getCostLimit(),((Director) worker).getPosition());
                            String save = in.nextLine();
            } else
            {
                view.deleteSalesMan(worker.getPesel(), worker.getName(),
                        worker.getSurname(), worker.getJobsPhoneNumber(), worker.getSalary(),((SalesMan) worker).
                        getProvision(),((SalesMan) worker).getProvisionLimit(),((SalesMan) worker).getPosition());
                String save = in.nextLine();
            }
        }while(wybor == true);
    }
    public void PrintHashMap()
    {
        for(String pesel: service.listaPracownikow.keySet())
        {
            Worker worker = service.getWorker(pesel);
                if(worker.getClass() == Director.class)
                {
                    view.printDirector(worker.getPesel(), worker.getName(), worker.getSurname(), worker.getJobsPhoneNumber(), worker.getSalary(),
                            ((Director) worker).getJobsCardNumber(),
                            ((Director) worker).getCostLimit(),
                            ((Director) worker).getBonusMoney(),
                            ((Director) worker).getPosition());
                }else
                {
                    view.printSalesMan(
                            worker.getPesel(), worker.getName(), worker.getSurname(), worker.getJobsPhoneNumber(), worker.getSalary(),
                            ((SalesMan) worker).getProvision(),
                            ((SalesMan) worker).getProvisionLimit(),
                            ((SalesMan) worker).getPosition());

                }
                String k = in.nextLine();
        }
    }
    public void serializacja() throws IOException{
        boolean f=true;
        do {
            System.out.println("[Z]achowaj/[O]dtworz");
            String c = in.nextLine();
            if (c.charAt(0) == 'Z' || c.charAt(0) == 'z') {
                boolean t=true;
                do {
                    System.out.println("[G]zip/[Z]ip");
                    String s = in.nextLine();
                    //serializacja i kompresja
                    if (s.charAt(0) == 'G' || s.charAt(0) == 'g') {
                        FileOutputStream myFileOutStream
                                = new FileOutputStream(
                                "serializedMap");
                        ObjectOutputStream myObjectOutStream
                                = new ObjectOutputStream(myFileOutStream);

                        myObjectOutStream.writeObject(service.listaPracownikow);
                        myObjectOutStream.close();
                        myFileOutStream.close();
                        System.out.println("Serialization completed");
                        f = false;
                    } else if (c.charAt(0) == 'Z' || c.charAt(0) == 'z') {
                        //do zip
                        f = false;
                    } else {
                        view.Error();

                    }
                }while(t==true);
                f=false;
            } else if (c.charAt(0) == 'O' || c.charAt(0) == 'o') {
                HashMap<String, Worker> newHashMap = null;

                try {
                    FileInputStream fileInput = new FileInputStream(
                            "serializedMap");

                    ObjectInputStream objectInput
                            = new ObjectInputStream(fileInput);

                    newHashMap = (HashMap)objectInput.readObject();

                    objectInput.close();
                    fileInput.close();
                }

                catch (IOException obj1) {
                    obj1.printStackTrace();
                    return;
                }

                catch (ClassNotFoundException obj2) {
                    System.out.println("Class not found");
                    obj2.printStackTrace();
                    return;
                }

                System.out.println("Deserializing  HashMap..");

                service.listaPracownikow = newHashMap;


                f=false;
            } else {
                view.Error();

            }
        }while(f==true);


    }
    }



