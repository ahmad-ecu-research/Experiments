using System.ComponentModel.DataAnnotations;

public class Contact
{
    public int Id { get; set; }

    [Required(ErrorMessage = "Name is required.")]
    [StringLength(100, ErrorMessage = "Name must be less than 100 characters.")]
    public string Name { get; set; }

    [Required(ErrorMessage = "Email is required.")]
    [EmailAddress(ErrorMessage = "Invalid Email Address")]
    public string Email { get; set; }

    [Required(ErrorMessage = "Message is required.")]
    [StringLength(500, ErrorMessage = "Message must be less than 500 characters.")]
    public string Message { get; set; }
}
