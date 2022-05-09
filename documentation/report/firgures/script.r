setwd('~/Documents/programing_projects/schduling/documentation/report/firgures/data/')

data1 <- read.csv('mng05mpw50tt30.txt')
plot(
    main = 'MNG 5 MPW 50',
    y = data1$pla,
    x = data1$time,
    pch = 8,
    col = '#000000',
    xlab = 'Time Quantum',
    ylab = 'Available Proc List Space'
)
data2 <- read.csv('mng05mpw60tt30.txt')
plot(
    main = 'MNG 5, MPW 60',
    y = data2$pla,
    x = data2$time,
    pch = 8,
    col = '#000000',
    xlab = 'Time Quantum',
    ylab = 'Available Proc List Space'
)
data3 <- read.csv('mng05mpw75tt30.txt')
plot(
    main = 'MNG 5, MPW 75',
    y = data3$pla,
    x = data3$time,
    pch = 8,
    col = '#000000',
    xlab = 'Time Quantum',
    ylab = 'Available Proc List Space'
)
data4 <- read.csv('mng10mpw75tt30.txt')
plot(
    main = 'MNG 10, MPW 75',
    y = data4$pla,
    x = data4$time,
    pch = 8,
    col = '#000000',
    xlab = 'Time Quantum',
    ylab = 'Available Proc List Space'
)
data5 <- read.csv('mng10mpw75tt30.txt')
plot(
    main = 'MNG 15, MPW 75',
    y = data5$pla,
    x = data5$time,
    pch = 8,
    col = '#000000',
    xlab = 'Time Quantum',
    ylab = 'Available Proc List Space'
)
