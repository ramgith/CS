# Set the source folder path
$sourceFolderPath = ""

# Set the destination folder path for moving the compressed file
$moveDestinationFolderPath = ""

# Get the current hostname
$hostname = hostname

# Combine the hostname and the actual folder name
$newFolderName = "$hostname-$((Get-Item $sourceFolderPath).BaseName)"

# Combine the destination path for moving the compressed file
$compressedFilePath = Join-Path -Path $moveDestinationFolderPath -ChildPath "$newFolderName.zip"

# Compress the folder and overwrite if the file already exists
Compress-Archive -Path $sourceFolderPath -DestinationPath $compressedFilePath -Force

# Optionally, remove the original folder (commented out to keep the original folder)
# Remove-Item -Path $sourceFolderPath -Recurse -Force
