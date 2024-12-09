pipeline {
    agent any
    
    stages {
        stage('Checkout') {
            steps {
                git url: 'https://github.com/cansomebodyhelp/sp_4', credentialsId: 'access_for_jenkins'
            }
        }
        
        stage('Build') {
            steps {
                script {
                    try {
                        bat '"G:\\visual\\MSBuild\\Current\\Bin\\MSBuild.exe" emakov-test.sln /p:Configuration=Debug /p:Platform=x64 /m'
                    } catch (Exception e) {
                        echo "Build error: ${e.message}"
                        currentBuild.result = 'FAILURE'
                        error("Pipeline stopped due to build failure.")
                    }
                }
            }
        }
        
        stage('Test') {
            steps {
                script {
                    try {
                        bat '"G:\\sys_prog\\lab4\\emakov-test\\x64\\Debug\\emakov-test.exe"'
                    } catch (Exception e) {
                        echo "Test error: ${e.message}"
                        currentBuild.result = 'FAILURE'
                        error("Pipeline stopped due to test execution failure.")
                    }
                }
            }
        }
    }
    
    post {
        always {
            cleanWs()
        }
        
        failure {
            echo "Pipeline failed. Check logs to fix the issues."
        }
        
        success {
            echo "Pipeline completed successfully!"
        }
    }
}