spark-submit \
	--class "SparkKMeans" \
	--master local[4] \
	--driver-cores 4 \
	target/scala-2.11/tarea3_2.11-1.0.jar $1 $2