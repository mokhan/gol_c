task :default => :test

task :clean do
  sh "rm -f gol"
  sh "rm -f test"
  sh "rm -fr gol.dSYM"
  sh "rm -fr test.dSYM"
end

task :run => :clean do
  sh "gcc -std=c99 -Wall -g gol.c main.c -o gol"
  sh "./gol"
end

task :test => :clean do
  sh "gcc -std=c99 -Wall -g gol.c gol_test.c -o test"
  sh "./test"
end