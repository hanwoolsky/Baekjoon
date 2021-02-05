import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
 
public class Main {
     
    final static int MAX_N = 250000;
     
    private static Num[] nums = new Num[MAX_N];
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
         
        int N, K, K2, i;
        long ans;
        StringTokenizer st;
         
        for (i = 0; i < MAX_N; i++) nums[i] = new Num();
         
        PriorityQueue<Num> lowQue = new PriorityQueue<Num>(Collections.reverseOrder());
        PriorityQueue<Num> highQue = new PriorityQueue<Num>();
         
        while (!lowQue.isEmpty()) lowQue.poll();
        while (!highQue.isEmpty()) highQue.poll();
         
        st = new StringTokenizer(br.readLine());
         
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        K2 = (K - 1) >> 1;
         
        for (i = 0; i <= K2; i++) {
            nums[i].set(i, Integer.parseInt(br.readLine()));
            lowQue.offer(nums[i]);
        }
        for (i = K2 + 1; i < K; i++) {
            nums[i].set(i, Integer.parseInt(br.readLine()));
            if (lowQue.peek().compareTo(nums[i]) > 0) {
                highQue.offer(lowQue.poll());
                lowQue.offer(nums[i]);
            }
            else {
                highQue.offer(nums[i]);
            }
        }
        ans = lowQue.peek().num;
         
        for (i = K; i < N; i++) {
            nums[i].set(i, Integer.parseInt(br.readLine()));

            if (lowQue.peek().compareTo(nums[i - K]) < 0) {
                //  삭제될 값이 큰 Priority Queue에 존재할 때
                highQue.offer(nums[i]);
            }
            else {
                //  삭제될 값이 작은  Priority Queue에 존재할 때
                lowQue.offer(nums[i]);
            }

            //  K 범위 이전의 값을 제거함
            while (!lowQue.isEmpty() && lowQue.peek().idx <= i - K) lowQue.poll();
            while (!highQue.isEmpty() && highQue.peek().idx <= i - K) highQue.poll();   
             
            if (!highQue.isEmpty() && lowQue.peek().compareTo(highQue.peek()) > 0) {
                lowQue.offer(highQue.poll());
                highQue.offer(lowQue.poll());
                while (!lowQue.isEmpty() && lowQue.peek().idx <= i - K) lowQue.poll();
            }
             
            ans += lowQue.peek().num;
        }
         
        bw.write(ans + "\n");
        bw.flush();
    }
     
    private static class Num implements Comparable<Num> {
        int idx;
        int num;
         
        public void set(int idx, int num) {
            this.idx = idx;
            this.num = num;
        }
         
        @Override
        public int compareTo(Num n) {
            if (this.num == n.num) return this.idx - n.idx;
            else return this.num - n.num;
        }
    }
 
}
