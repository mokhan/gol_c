task :default => :test

task :clean do
  sh "rm -f bin/gol"
  sh "rm -f bin/gol_test"
end

task :run => :clean do
  sh "gcc -std=c99 -Wall -g src/gol.c src/main.c -o bin/gol"
  sh "./bin/gol"
end

task :test => :clean do
  sh "gcc -std=c99 -Wall -g src/gol.c src/gol_test.c -o bin/gol_test"
  sh "./bin/gol_test"
end
