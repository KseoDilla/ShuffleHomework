//A Jenkinsfile to validate my image
pipeline {
    agent {
        label 'generic'
    }
    stages {
        stage("Lint")
        {
            steps 
            {
                sh "docker run --rm -i hadolint/hadolint hadolint - < docker/Dockerfile"
            }
        }
        stage('Build')
        {
            steps
            {
                script
                {
                    service = docker.build('shuffle-service',"-f docker/Dockerfile .")
                }
            }
        }
        stage('Coverage')
        {
            /*agent
            {
                dockerfile
                {
                    reuseNode true
                    filename 'Dockerfile'
                    dir 'docker'
                    label 'shuffle-buildenv'
                    args '--target shuffle-buildenv'
                }
            }*/
            steps
            {
                script
                {
                    buildenv = docker.build('shuffle-buildenv', "--target shuffle-buildenv -f docker/Dockerfile .")
                    buildenv.inside
                    {
                        sh 'make test ; make coverage'
                        //strange gcovr bug reporting not covering any lines
                        //publishCoverage adapters: [coberturaAdapter('src/bin/src_coverage.xml')]
                        publishCoverage adapters: [coberturaAdapter('unitTest/bin/unitTest_coverage.xml')]
                    }
                }
            }
        }
    }
    post
    {
        cleanup
        {
            deleteDir()
        }
    }
}
