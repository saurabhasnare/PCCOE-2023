import java.util.*;

public class JobSchedule1 implements Comparable<JobSchedule1> {

    String jName;
    int profit;
    int deadline;

    // ... (constructor and getter/setter methods)

   
    public void setjName(String jName) {
        this.jName = jName;
    }

    public void setProfit(int profit) {
        this.profit = profit;
    }

    public void setDeadline(int deadline) {
        this.deadline = deadline;
    }

    public String getjName() {
        return jName;
    }

    public int getProfit() {
        return profit;
    }

    public int getDeadline() {
        return deadline;
    }

    public JobSchedule1(String jName,int profit,int deadline){
	
		this.jName=jName;
		this.profit=profit;
		this.deadline=deadline;
	
	}

    public static void main(String args[]) {
        ArrayList<JobSchedule1> lst = new ArrayList<>();

        // lst.add(new JobSchedule1("j1", 35, 1));
        // lst.add(new JobSchedule1("j2", 30, 2));
        // lst.add(new JobSchedule1("j3", 25, 1));
        // lst.add(new JobSchedule1("j4", 20, 2));
        // lst.add(new JobSchedule1("j5", 1, 3));

        lst.add(new JobSchedule1("j1",35,3));
    lst.add(new JobSchedule1("j2",30,4));
    lst.add(new JobSchedule1("j3",25,4));
    lst.add(new JobSchedule1("j4",20,1));
    lst.add(new JobSchedule1("j5",15,3));

    lst.add(new JobSchedule1("j6",12,1));

    lst.add(new JobSchedule1("j7",5,2));

	// lst.add(new JobSchedule1("j5",1,3));

        Collections.sort(lst);

        System.out.println("Sorted Sequence of jobs is");
        System.out.println("job name \t profit \t deadline");

        for (JobSchedule1 o : lst) {
            System.out.println(o.getjName() + "\t" + o.getProfit() + "\t" + o.getDeadline());
        }

        int maxDeadline = 0;
        for (JobSchedule1 o : lst) {
            maxDeadline = Math.max(maxDeadline, o.getDeadline());
        }

        int[] schedule = new int[maxDeadline];
        Arrays.fill(schedule, -1); // Initialize the schedule array with -1 to indicate empty slots

        int totalProfit = 0;

        for (JobSchedule1 job : lst) {
            for (int j = job.getDeadline() - 1; j >= 0; j--) {
                if (schedule[j] == -1) {
                    schedule[j] = job.getProfit();
                    totalProfit += job.getProfit();
                    System.out.println(job.getProfit());

                    break;
                }

            }
        }

        System.out.println("Final Sequence of jobs is");
        System.out.println("job name \t profit \t deadline");

        for (int i = 0; i < maxDeadline; i++) {
            if (schedule[i] != -1) {
                for (JobSchedule1 job : lst) {
                    if (job.getProfit() == schedule[i]) {
                        System.out.println(job.getjName() + "\t" + job.getProfit() + "\t" + job.getDeadline());
                        break;
                    }
                }
            }
        }

        System.out.println("Total Profit: " + totalProfit);
    }

    @Override
    public int compareTo(JobSchedule1 o) {
        return o.profit - this.profit; // Descending order based on profit
    }
}
