#!/bin/sh
echo Starting Codeforces Contest Wizard...
name=contest-wizard-starter-1.0-`date +%N`.jar
url=http://codeforces.org/s/96024/wizard/contest-wizard-starter-1.0-SNAPSHOT.jar?session=b4017682516dd693ce3d93b16808c023
cd $TEMP
wget --output-document=$name $url
java -cp $name -Xss5m -Xmx1024m com.codeforces.contestwizard.Main QmFjaCBLaG9hIENvZGUgQ2hhbGxlbmdlICMx \# MTgw MTA1NzI5L3NhbmRib3gvY29udGVzdC56aXA Kk5hbWluZQ S3RCZVY2aFl6cWVDM2xqM2U0LVoyS2hicWVZSTZPR0pYMlFrN0tGYThSQm1CMHRUZw ZW4 ZmFsc2U \# \# \# &

