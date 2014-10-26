task :default => :test

task :clean do
  sh "rm -f gol"
  sh "rm -f gol_test"
  sh "rm -fr gol.dSYM"
  sh "rm -fr gol_test.dSYM"
end

task :run => :clean do
  sh "gcc -std=c99 -Wall -g gol.c main.c -o gol"
  sh "./gol"
end

task :test => :clean do
  sh "gcc -std=c99 -Wall -g gol.c gol_test.c -o gol_test"
  sh "./gol_test"
end
