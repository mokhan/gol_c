task :default => :test

task :clean do
  sh "rm -f *.out"
  sh "rm -f gol"
end

task :run => :clean do
  sh "gcc -std=c99 -Wall -g gol.c main.c -o gol"
  sh "./gol.out"
end

task :test => :clean do
  sh "gcc -std=c99 -Wall -g gol.c gol_test.c -o test"
  sh "./test.out"
end
