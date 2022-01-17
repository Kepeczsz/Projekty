import Workers.Controller.WorkersController;
import Workers.Service.WorkerService;
import Workers.View.WorkerListView;

import java.io.IOException;

public class MvcMenu {
    public static void main(String[] args) throws IOException {
        WorkersController workersController = new WorkersController();
        WorkerService workerService = new WorkerService();
        WorkerListView workerListView = new WorkerListView();

        workersController.Controller();

    }
}
