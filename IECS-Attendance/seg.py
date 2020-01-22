import face_recognition
image = face_recognition.load_image_file("/mnt/hgfs/share/raw1.jpg")
face_locations = face_recognition.face_locations(image)
